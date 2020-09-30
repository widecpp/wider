#include "client-area-layout.hpp"
#include <pangomm/fontdescription.h>
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

    this->draw_text("Nice text", cr, 300, 20, 1);
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

void ClientAreaLayout::draw_text(const std::string &text, const Cairo::RefPtr<Cairo::Context>& cr, double px, double py, double scale)
{
    cr->save();
    cr->set_source_rgb(1, 1, 1);
    Pango::FontDescription font;

    font.set_family("Consolas");
    font.set_absolute_size(12.0 * PANGO_SCALE*scale);

    auto layout = this->create_pango_layout(text);
    layout->set_font_description(font);
    int iWidth  {0};
    int iHeight {0};

    layout->get_pixel_size(iWidth, iHeight);
    cr->move_to(px - iWidth / 2, py - iHeight / 2);
    layout->show_in_cairo_context(cr);
    cr->restore();
}