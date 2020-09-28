#include "title-bar-layout.hpp"
using namespace wider::ui::layout;

TitleBarLayout::TitleBarLayout()
{
    add_events(Gdk::BUTTON1_MOTION_MASK | Gdk::BUTTON_PRESS_MASK | Gdk::POINTER_MOTION_MASK);
    this->set_size_request(-1, 30);
}

bool TitleBarLayout::on_draw(Cairo::RefPtr<Cairo::Context> const & cr)
{
    auto isActive = get_window()->get_toplevel()->get_state() == Gdk::WINDOW_STATE_FOCUSED;
    Gdk::RGBA headerColor((isActive ? "#3c3c3c" : "#333333"));
    auto h = this->get_height();
    auto w = this->get_width();
	cr->set_source_rgb(headerColor.get_red(), headerColor.get_green(), headerColor.get_blue());
    cr->rectangle(0, 0, w, 30);
    cr->fill();
	return true;
}

bool TitleBarLayout::on_motion_notify_event(GdkEventMotion *event)
{
    this->queue_draw();
    return false;
}

bool TitleBarLayout::on_button_press_event(GdkEventButton* event)
{
    this->queue_draw();
    return false;
}