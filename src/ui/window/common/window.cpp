#include "window.hpp"
#include "ui/window/gtk/window-gtk.hpp"
#include "core/common/app.hpp"
using namespace wider::ui::window;

Window::Window(wider::core::WiderApp &app) :
	app_(app)
{
}

void Window::onInitialized()
{
	app_.onWindowAdded(this);
}

std::unique_ptr<Window> Window::create(wider::core::WiderApp &app, int w, int h)
{
	return std::make_unique<WindowGtk>(app, w, h);
}