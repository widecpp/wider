#include "main-layout.hpp"
#include <gdkmm/rgba.h>
#include <gdkmm/device.h>
using namespace wider::ui::layout;

MainLayout::MainLayout()
{
    // add_events(Gdk::BUTTON1_MOTION_MASK | Gdk::BUTTON_PRESS_MASK | Gdk::POINTER_MOTION_MASK);

    hbox_.pack_start(side_, Gtk::PACK_SHRINK);
    hbox_.pack_start(panel_, Gtk::PACK_SHRINK);
    hbox_.pack_start(client_);
    hbox_.show_all();

    this->pack_start(title_, Gtk::PACK_SHRINK);
    this->pack_start(hbox_);
    this->pack_start(status_, Gtk::PACK_SHRINK);
    this->show_all();
}
