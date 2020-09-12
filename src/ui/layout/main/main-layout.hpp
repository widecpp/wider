#ifndef MAIN_LAYOUT
#define MAIN_LAYOUT

#include "ui/layout/common/layout.hpp"
#include <gtkmm.h>
#include <gtkmm/drawingarea.h>

namespace wider::ui::layout
{
    class MainLayout :
        public Layout, public Gtk::DrawingArea
    {
    public:
    };
}

#endif // MAIN_LAYOUT
