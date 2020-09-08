#include "window.hpp"
#include "ui/window/gtk/window-gtk.hpp"
using namespace wider::ui::window;

std::unique_ptr<Window> Window::create(int w, int h)
{
	return std::make_unique<WindowGtk>(w, h);
}