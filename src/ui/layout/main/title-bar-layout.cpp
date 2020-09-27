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
    /*Gdk::RGBA backColor("#252526");
    Gdk::RGBA sideColor("#333333");
    Gdk::RGBA statusColor("#007acc");*/
	cr->set_source_rgb(headerColor.get_red(), headerColor.get_green(), headerColor.get_blue());
    cr->rectangle(0, 0, this->get_width(), 30);
    cr->fill();

    /*cr->set_source_rgb(statusColor.get_red(), statusColor.get_green(), statusColor.get_blue());
    cr->rectangle(0, this->get_height() - 22, this->get_width(), 22);
    cr->fill();

    cr->set_source_rgb(sideColor.get_red(), sideColor.get_green(), sideColor.get_blue());
    cr->rectangle(0, 30, 48, this->get_height() - (22 + 30));
    cr->fill();

    cr->set_source_rgb(backColor.get_red(), backColor.get_green(), backColor.get_blue());
    cr->rectangle(48, 30, this->get_width() - 48, this->get_height() - (22 + 30));
    cr->fill();*/
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