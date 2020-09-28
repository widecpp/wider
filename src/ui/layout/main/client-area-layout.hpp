#ifndef CLIENT_AREA_LAYOUT
#define CLIENT_AREA_LAYOUT

#include <gtkmm.h>
#include <gtkmm/drawingarea.h>

namespace wider::ui::layout
{
    class ClientAreaLayout :
        public Gtk::DrawingArea
    {
    public:
        ClientAreaLayout();
    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

        bool on_motion_notify_event(GdkEventMotion *event) override;
        bool on_button_press_event(GdkEventButton* event) override;
    };
}


#endif // CLIENT_AREA_LAYOUT
