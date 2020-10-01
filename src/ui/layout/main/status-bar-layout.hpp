#ifndef STATUS_BAR_LAYOUT
#define STATUS_BAR_LAYOUT

#include <gtkmm.h>
#include <gtkmm/layout.h>

namespace wider::ui::layout
{
    class StatusBarLayout :
        public Gtk::Layout
    {
    public:
        StatusBarLayout();
    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

        bool on_motion_notify_event(GdkEventMotion *event) override;
        bool on_button_press_event(GdkEventButton* event) override;
    };
}

#endif // STATUS_BAR_LAYOUT
