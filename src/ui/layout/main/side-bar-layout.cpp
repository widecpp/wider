#include "side-bar-layout.hpp"
using namespace wider::ui::layout;

SideBarLayout::SideBarLayout()
{
    add_events(Gdk::BUTTON1_MOTION_MASK | Gdk::BUTTON_PRESS_MASK | Gdk::POINTER_MOTION_MASK);
    this->set_size_request(48, -1);
}

bool SideBarLayout::on_draw(Cairo::RefPtr<Cairo::Context> const & cr)
{
    auto h =  this->get_height();
    auto w = this->get_width();
    Gdk::RGBA sideColor("#333333");

    cr->set_source_rgb(sideColor.get_red(), sideColor.get_green(), sideColor.get_blue());
    cr->rectangle(0, 0, 48, this->get_height());
    cr->fill();

	return Gtk::Layout::on_draw(cr);
}

bool SideBarLayout::on_motion_notify_event(GdkEventMotion *event)
{
    this->queue_draw();
    return false;
}

bool SideBarLayout::on_button_press_event(GdkEventButton* event)
{
    this->queue_draw();
    return false;
}