#include "ui/window/gtk/window-gtk.hpp"
#include <gtkmm/window.h>
using namespace wider::ui::window;

namespace wider::ui::window
{
	struct WindowGtk::Impl
	{
		Gtk::Window window;
	};
}

WindowGtk::WindowGtk(wider::core::WiderApp &app, int width, int height) :
	Window(app), impl_(std::make_unique<Impl>())
{
	impl_->window.resize(width, height);
	impl_->window.set_title("wIDEr");
	onInitialized();
}

WindowGtk::~WindowGtk() = default;

WindowSize WindowGtk::getSize() const
{
	int x, y;
	impl_->window.get_size(x, y);
	return {x ,y};
}

void WindowGtk::move(int x, int y)
{

}

void *WindowGtk::getHandle()
{
	return static_cast<void *>(&impl_->window);
}