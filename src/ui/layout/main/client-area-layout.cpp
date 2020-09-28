#include "client-area-layout.hpp"
using namespace wider::ui::layout;

ClientAreaLayout::ClientAreaLayout()
{
    add_events(Gdk::BUTTON1_MOTION_MASK | Gdk::BUTTON_PRESS_MASK | Gdk::POINTER_MOTION_MASK);
}

bool ClientAreaLayout::on_draw(Cairo::RefPtr<Cairo::Context> const & cr)
{
    auto h =  this->get_height();
    auto w = this->get_width();
    Gdk::RGBA backColor("#1e1e1e");

    cr->set_source_rgb(backColor.get_red(), backColor.get_green(), backColor.get_blue());
    cr->rectangle(0, 0, this->get_width(), this->get_height());
    cr->fill();
	return true;
}

bool ClientAreaLayout::on_motion_notify_event(GdkEventMotion *event)
{
    this->queue_draw();
    return false;
}

bool ClientAreaLayout::on_button_press_event(GdkEventButton* event)
{
    this->queue_draw();
    return false;
}