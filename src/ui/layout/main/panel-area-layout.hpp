#ifndef PANEL_AREA_LAYOUT
#define PANEL_AREA_LAYOUT

#include <gtkmm.h>
#include <gtkmm/drawingarea.h>

namespace wider::ui::layout
{
    class PanelAreaLayout :
        public Gtk::DrawingArea
    {
    public:
        PanelAreaLayout();
    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

        bool on_motion_notify_event(GdkEventMotion *event) override;
        bool on_button_press_event(GdkEventButton* event) override;
    };
}

#endif // PANEL_AREA_LAYOUT
