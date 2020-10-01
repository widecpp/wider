#ifndef TITLE_BAR_LAYOUT
#define TITLE_BAR_LAYOUT

#include <gtkmm.h>
#include <gtkmm/layout.h>

namespace wider::ui::layout
{
    class TitleBarLayout :
        public Gtk::Layout
    {
    public:
        TitleBarLayout();
    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

        bool on_motion_notify_event(GdkEventMotion *event) override;
        bool on_button_press_event(GdkEventButton* event) override;
    };
}

#endif // TITLE_BAR_LAYOUT
