#include "main-layout.hpp"
#include <gdkmm/rgba.h>
#include <gdkmm/device.h>
using namespace wider::ui::layout;

MainLayout::MainLayout()
{
    add_events(Gdk::BUTTON1_MOTION_MASK | Gdk::BUTTON_PRESS_MASK | Gdk::POINTER_MOTION_MASK);
}

bool MainLayout::on_draw(Cairo::RefPtr<Cairo::Context> const & cr)
{
    auto isActive = get_window()->get_toplevel()->get_state() == Gdk::WINDOW_STATE_FOCUSED;
    Gdk::RGBA headerColor((isActive ? "#3c3c3c" : "#333333"));
    Gdk::RGBA sideColor("#333333");
    Gdk::RGBA statusColor("#007acc");
	cr->set_source_rgb(headerColor.get_red(), headerColor.get_green(), headerColor.get_blue());
    cr->rectangle(0, 0, this->get_width(), 30);
    cr->fill();

    cr->set_source_rgb(statusColor.get_red(), statusColor.get_green(), statusColor.get_blue());
    cr->rectangle(0, this->get_height() - 22, this->get_width(), 22);
    cr->fill();

    cr->set_source_rgb(sideColor.get_red(), sideColor.get_green(), sideColor.get_blue());
    cr->rectangle(0, 30, 48, this->get_height() - (22 + 30));
    cr->fill();
	return true;
}

bool MainLayout::on_motion_notify_event(GdkEventMotion *event)
{
    this->queue_draw();
    return false;
}

bool MainLayout::on_button_press_event(GdkEventButton* event)
{
    auto wnd = get_window()->get_toplevel();
    if (event->type == GDK_BUTTON_PRESS && event->button == 1)
    {
        if (event->y < 4)
            wnd->begin_resize_drag(Gdk::WINDOW_EDGE_NORTH, event->button, event->x_root, event->y_root, event->time);
        else if (event->y > this->get_height() - 4)
            wnd->begin_resize_drag(Gdk::WINDOW_EDGE_SOUTH, event->button, event->x_root, event->y_root, event->time);
        else if (event->y < 30)
            wnd->begin_move_drag(event->button, event->x_root, event->y_root, event->time);
    }
    
    this->queue_draw();
    return false;
}