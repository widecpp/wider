#include "panel-area-layout.hpp"
using namespace wider::ui::layout;

PanelAreaLayout::PanelAreaLayout()
{
    add_events(Gdk::BUTTON1_MOTION_MASK | Gdk::BUTTON_PRESS_MASK | Gdk::POINTER_MOTION_MASK);
    this->set_size_request(200, -1);

    fileStore_ = Gtk::TreeStore::create(columns_);
    fileTree_.set_model(fileStore_);
    auto sc = this->fileTree_.get_style_context();
    
    auto cssProvider = Gtk::CssProvider::create();
    cssProvider->load_from_data(".pidaras {background: #252526; color: white;}");
    sc->add_provider(cssProvider, 1000);
    sc->add_class("pidaras");
    //fileTree_.set_name("treeview");

    Gtk::TreeViewColumn *filenameViewColumn = new Gtk::TreeViewColumn("Filename", columns_.filename);

    this->fileTree_.append_column(*filenameViewColumn);
    this->put(fileTree_, 0, 0);
    
    this->show_all();

    this->fileTree_.set_size_request(200, 300);

    auto it = fileStore_->append();
    it->set_value(columns_.filename, Glib::ustring("test string"));
    it = fileStore_->append();
    it->set_value(columns_.filename, Glib::ustring("test string2"));

    fileTree_.set_headers_visible(false);
    // fileTree_.set_child_visible(true);
}

bool PanelAreaLayout::on_draw(Cairo::RefPtr<Cairo::Context> const & cr)
{
    auto h =  this->get_height();
    auto w = this->get_width();
    cr->save();
    Gdk::RGBA backColor("#252526");

    cr->set_source_rgb(backColor.get_red(), backColor.get_green(), backColor.get_blue());
    cr->rectangle(0, 0, this->get_width(), this->get_height());
    cr->fill();
    cr->restore();
    return Gtk::Layout::on_draw(cr);
}

bool PanelAreaLayout::on_motion_notify_event(GdkEventMotion *event)
{
    this->queue_draw();
    return false;
}

bool PanelAreaLayout::on_button_press_event(GdkEventButton* event)
{
    this->queue_draw();
    return false;
}