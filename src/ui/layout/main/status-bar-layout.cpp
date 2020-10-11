#include "status-bar-layout.hpp"
using namespace wider::ui::layout;

StatusBarLayout::StatusBarLayout()
{
    add_events(Gdk::BUTTON1_MOTION_MASK | Gdk::BUTTON_PRESS_MASK | Gdk::POINTER_MOTION_MASK);
    this->set_size_request(-1, 22);
}

bool StatusBarLayout::on_draw(Cairo::RefPtr<Cairo::Context> const & cr)
{
    auto h =  this->get_height();
    auto w = this->get_width();
    Gdk::RGBA statusColor("#007acc");
    cr->set_source_rgb(statusColor.get_red(), statusColor.get_green(), statusColor.get_blue());
    cr->rectangle(0, h - 22, w, 22);
    cr->fill();
	return Gtk::Layout::on_draw(cr);
}

bool StatusBarLayout::on_motion_notify_event(GdkEventMotion *event)
{
    this->queue_draw();
    return false;
}

bool StatusBarLayout::on_button_press_event(GdkEventButton* event)
{
    this->queue_draw();
    return false;
}