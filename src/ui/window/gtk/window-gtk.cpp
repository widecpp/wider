#include "ui/window/gtk/window-gtk.hpp"
#include "ui/layout/common/layout.hpp"
#include <gtkmm/window.h>
#include <vector>
#include <memory>
using namespace wider::ui::window;

namespace wider::ui::window
{
	struct WindowGtk::Impl
	{
		Gtk::Window window;
		std::vector<std::shared_ptr<wider::ui::layout::Layout>> layouts;
	};
}

WindowGtk::WindowGtk(wider::core::WiderApp &app, int width, int height) :
	Window(app), impl_(std::make_unique<Impl>())
{
	impl_->window.set_size_request(200, 100);
	impl_->window.resize(width, height);
	impl_->window.set_title("wIDEr");
	impl_->window.set_decorated(false);
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

void WindowGtk::applyLayout(wider::ui::layout::Layout *layout)
{
	impl_->layouts.push_back(layout->shared_from_this());
	auto widget = dynamic_cast<Gtk::Widget*>(layout);
	impl_->window.add(*widget);
	widget->show();
}

void *WindowGtk::getHandle()
{
	return static_cast<void *>(&impl_->window);
}