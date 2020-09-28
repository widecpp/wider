#include "panel-area-layout.hpp"
using namespace wider::ui::layout;

PanelAreaLayout::PanelAreaLayout()
{
    add_events(Gdk::BUTTON1_MOTION_MASK | Gdk::BUTTON_PRESS_MASK | Gdk::POINTER_MOTION_MASK);
    this->set_size_request(200, -1);
}

bool PanelAreaLayout::on_draw(Cairo::RefPtr<Cairo::Context> const & cr)
{
    auto h =  this->get_height();
    auto w = this->get_width();
    Gdk::RGBA backColor("#252526");

    cr->set_source_rgb(backColor.get_red(), backColor.get_green(), backColor.get_blue());
    cr->rectangle(0, 0, this->get_width(), this->get_height());
    cr->fill();
	return true;
}

bool PanelAreaLayout::on_motion_notify_event(GdkEventMotion *event)
{
    this->queue_draw();
    return false;
}

bool PanelAreaLayout::on_button_press_event(GdkEventButton* event)
{
    this->queue_draw();
    return false;
}