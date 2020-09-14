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
    protected:
        // Override default signal handler:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    };
}

#endif // MAIN_LAYOUT
