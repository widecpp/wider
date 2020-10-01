#ifndef SIDE_BAR_LAYOUT
#define SIDE_BAR_LAYOUT

#include <gtkmm.h>
#include <gtkmm/layout.h>

namespace wider::ui::layout
{
    class SideBarLayout :
        public Gtk::Layout
    {
    public:
        SideBarLayout();
    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

        bool on_motion_notify_event(GdkEventMotion *event) override;
        bool on_button_press_event(GdkEventButton* event) override;
    };
}

#endif // SIDE_BAR_LAYOUT
