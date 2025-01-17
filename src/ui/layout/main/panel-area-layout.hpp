#ifndef PANEL_AREA_LAYOUT
#define PANEL_AREA_LAYOUT

#include <gtkmm.h>
#include <gtkmm/layout.h>
#include <gtkmm/treeview.h>
#include <gtkmm/treestore.h>

namespace wider::ui::layout
{
    class PanelAreaLayout :
        public Gtk::Layout
    {
    public:
        PanelAreaLayout();
    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

        bool on_motion_notify_event(GdkEventMotion *event) override;
        bool on_button_press_event(GdkEventButton* event) override;
    private:

        class FileModelColumns : public Gtk::TreeModel::ColumnRecord
        {
        public:
            Gtk::TreeModelColumn<Glib::ustring> filename;
            FileModelColumns() { add(filename);}
        } columns_;
        // Временно, потом уберем нахрен отсюда в апишку
        Gtk::TreeView fileTree_;
        Glib::RefPtr<Gtk::TreeStore> fileStore_;
    };
}

#endif // PANEL_AREA_LAYOUT
