#include "app-gtk.hpp"
#include "ui/window/gtk/window-gtk.hpp"
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <algorithm>

using namespace wider::core;

namespace wider::core
{
	struct AppGtk::AppImpl
	{
		Glib::RefPtr<Gtk::Application> app;
	};
}

AppGtk::AppGtk(int argc, char **argv):
	WiderApp(argc, argv), impl_(std::make_unique<AppImpl>())
{
	impl_->app = Gtk::Application::create(argc, argv, "org.widecpp.wider.wider");
}

AppGtk::~AppGtk()
{
}

int AppGtk::run(wider::ui::window::Window *wnd)
{
	initApp();
	auto windowGtk = dynamic_cast<wider::ui::window::WindowGtk*>(wnd);
	auto handle = static_cast<Gtk::Window*>(windowGtk->getHandle());
	return impl_->app->run(*handle);
}

void AppGtk::onWindowAdded(wider::ui::window::Window *wnd)
{
	auto windowGtk = dynamic_cast<wider::ui::window::WindowGtk*>(wnd);
	auto handle = static_cast<Gtk::Window*>(windowGtk->getHandle());
	auto windows = impl_->app->get_windows();
	if (std::find(windows.begin(), windows.end(), handle) == windows.end())
		impl_->app->add_window(*handle);
}