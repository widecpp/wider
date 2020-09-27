#include "ui/window/gtk/window-gtk.hpp"
#include "ui/layout/common/layout.hpp"
#include <gtkmm/window.h>
#include <vector>
#include <memory>
using namespace wider::ui::window;

#include <iostream>
namespace wider::ui::window
{
	struct WindowGtk::Impl
	{
		Gtk::Window window;
		std::vector<std::shared_ptr<wider::ui::layout::Layout>> layouts;
	};
}

namespace
{
    enum Border : int
    {
        BorderNone = 0x0,
        BorderLeft = 0x1,
        BorderRight = 0x2,
        BorderTop = 0x4,
        BorderBottom = 0x8,
        BorderLeftTop = BorderLeft | BorderTop,
        BorderRightTop = BorderRight | BorderTop,
        BorderLeftBottom = BorderLeft | BorderBottom,
        BorderRightBottom = BorderRight | BorderBottom,
    };

    Gdk::WindowEdge getEdge(int border)
    {
        Gdk::WindowEdge edge;
        switch (border)
        {
        case BorderLeft:
            edge = Gdk::WINDOW_EDGE_WEST;
            break;
        case BorderRight:
            edge = Gdk::WINDOW_EDGE_EAST;
            break;
        case BorderTop:
            edge = Gdk::WINDOW_EDGE_NORTH;
            break;
        case BorderBottom:
            edge = Gdk::WINDOW_EDGE_SOUTH;
            break;
        case BorderLeftTop:
            edge = Gdk::WINDOW_EDGE_NORTH_WEST;
            break;
        case BorderRightTop:
            edge = Gdk::WINDOW_EDGE_NORTH_EAST;
            break;
        case BorderLeftBottom:
            edge = Gdk::WINDOW_EDGE_SOUTH_WEST;
            break;
        case BorderRightBottom:
            edge = Gdk::WINDOW_EDGE_SOUTH_EAST;
            break;
        }
        return edge;
    }

    Gdk::CursorType getCursorType(int border)
    {
        Gdk::CursorType cursorType;
        switch (border)
        {
        case BorderLeft:
            cursorType = Gdk::LEFT_SIDE;
            break;
        case BorderRight:
            cursorType = Gdk::RIGHT_SIDE;
            break;
        case BorderTop:
            cursorType = Gdk::TOP_SIDE;
            break;
        case BorderBottom:
            cursorType = Gdk::BOTTOM_SIDE;
            break;
        case BorderLeftTop:
            cursorType = Gdk::TOP_LEFT_CORNER;
            break;
        case BorderRightTop:
            cursorType = Gdk::TOP_RIGHT_CORNER;
            break;
        case BorderLeftBottom:
            cursorType = Gdk::BOTTOM_LEFT_CORNER;
            break;
        case BorderRightBottom:
            cursorType = Gdk::BOTTOM_RIGHT_CORNER;
            break;
        }
        return cursorType;
    }
}

WindowGtk::WindowGtk(wider::core::WiderApp &app, int width, int height) :
	Window(app), impl_(std::make_unique<Impl>())
{
	impl_->window.set_size_request(200, 100);
	impl_->window.resize(width, height);
	impl_->window.set_title("wIDEr");
	impl_->window.set_decorated(false);
    impl_->window.add_events(Gdk::POINTER_MOTION_MASK);
	onInitialized();

    std::cout << impl_->window.gobj() << std::endl;

	impl_->window.signal_motion_notify_event().connect([this](GdkEventMotion *event) -> bool
	{
        std::cout << event->window << ": " << (int) event->x << ", " << (int) event->y << std::endl;
		auto border = this->getBorder((int) event->x, (int) event->y);
		auto wnd = impl_->window.get_window();
		if (border)
		{
			auto cur = Gdk::Cursor::create(getCursorType(border));
			wnd->set_cursor(cur);
		} 
		else
			wnd->set_cursor();
		return true;
	});

	impl_->window.signal_button_press_event().connect([this](GdkEventButton *event) -> bool
	{
		if (event->type == GDK_BUTTON_PRESS && event->button == 1)
		{
			auto border = this->getBorder((int) event->x, (int) event->y);
			if (border)
			{
				auto edge = getEdge(border);
				impl_->window.begin_resize_drag(edge, event->button, (int) event->x_root, (int) event->y_root, event->time);
			}
			else if (event->y < 30)
				impl_->window.begin_move_drag(event->button, (int) event->x_root, (int) event->y_root, event->time);
		}
		
		return false;
	});
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

int WindowGtk::getBorder(int x, int y)
{
    int border = BorderNone;
    auto h = impl_->window.get_height();
    auto w = impl_->window.get_width();
    if (y < 4)
        border |= (int) BorderTop;
    if (y > h - 4)
        border |= (int) BorderBottom;
    if (x < 4)
        border |= (int) BorderLeft;
    if (x > w - 4)
        border |= (int) BorderRight;
    return border;
}