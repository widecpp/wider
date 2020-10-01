#ifndef CLIENT_AREA_LAYOUT
#define CLIENT_AREA_LAYOUT

#include <gtkmm.h>
#include <gtkmm/layout.h>

namespace wider::ui::layout
{
    class ClientAreaLayout :
        public Gtk::Layout
    {
    public:
        ClientAreaLayout();
    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

        bool on_motion_notify_event(GdkEventMotion *event) override;
        bool on_button_press_event(GdkEventButton* event) override;
    private:
        void draw_text(const std::string &text, const Cairo::RefPtr<Cairo::Context>& cr, double px, double py, double scale);
    };
}


#endif // CLIENT_AREA_LAYOUT
