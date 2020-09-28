#ifndef MAIN_LAYOUT
#define MAIN_LAYOUT

#include "ui/layout/common/layout.hpp"
#include <gtkmm.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/hvbox.h>

#include "title-bar-layout.hpp"
#include "status-bar-layout.hpp"
#include "side-bar-layout.hpp"
#include "panel-area-layout.hpp"
#include "client-area-layout.hpp"

namespace wider::ui::layout
{
    class MainLayout :
        public Layout, public Gtk::VBox
    {
    public:
        MainLayout();
    private:
        Gtk::HBox hbox_;
        TitleBarLayout title_;
        StatusBarLayout status_;
        
        SideBarLayout side_;
        PanelAreaLayout panel_;
        ClientAreaLayout client_;
    };
}

#endif // MAIN_LAYOUT
