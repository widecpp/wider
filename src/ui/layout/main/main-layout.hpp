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
        MainLayout();
    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

        bool on_motion_notify_event(GdkEventMotion *event) override;
        bool on_button_press_event(GdkEventButton* event) override;
    private:
        int getBorder(int x, int y);
    };
}

#endif // MAIN_LAYOUT
