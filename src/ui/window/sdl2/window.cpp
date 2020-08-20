#include "window.hpp"
#include <stdexcept>

#ifdef WIDER_SDL2_SYSTEM

using namespace wider::ui::window::sdl2;
constexpr char* windowClassKey = "wider_wnd";

Window::Window(int w, int h)
{
    const auto flags = 
        SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | // window flags
        SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI; // graphics flags
    window_ = SDL_CreateWindow("wIDEr",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        w, h, 
        flags);
    if (!window_)
        throw std::runtime_error("Unable to create window!");
	SDL_SetWindowData(window_, windowClassKey, this);
    configureGl(0, 0, w, h);
    initImgui();
	// Fix bug with resizing borderless window. (SDL 2.0.12)
	// Declaring by `SDL_WINDOW_RESIZABLE` flag on creation not helps
	SDL_SetWindowResizable(window_, SDL_TRUE);
}

Window::~Window()
{
    stopImgui();
    SDL_DestroyWindow(window_);
}

Window* Window::getByHandle(SDL_Window* window)
{
	return static_cast<Window*>(SDL_GetWindowData(window, windowClassKey));
}

Window* Window::getById(decltype(SDL_WindowEvent::windowID) windowId)
{
	return getByHandle(SDL_GetWindowFromID(windowId));
}

std::pair<int, int> Window::getSize()
{
	std::pair<int, int> size = {};
	SDL_GetWindowSize(window_, &size.first, &size.second);
	return size;
}

void Window::move(int x, int y)
{
	int tx, ty;
	SDL_GetWindowPosition(window_, &tx, &ty);
	tx += x;
	ty += y;
	SDL_SetWindowPosition(window_, tx, ty);
}

void Window::setHitTestCallback(std::function<WindowHitTest(int x, int y)> hitTest)
{
	hitTest_ = hitTest;
	SDL_SetWindowHitTest(window_, [](SDL_Window* win, const SDL_Point* area, void *userData) -> SDL_HitTestResult
	{
		auto *w = static_cast<Window*>(userData);
		const auto hResult = w->hitTest_(area->x, area->y);
		switch (hResult)
		{
		case WindowHitTest::Draggable:
			return SDL_HITTEST_DRAGGABLE;
		case WindowHitTest::ResizeTopLeft:
			return SDL_HITTEST_RESIZE_TOPLEFT;
		case WindowHitTest::ResizeTop:
			return SDL_HITTEST_RESIZE_TOP;
		case WindowHitTest::ResizeTopRight:
			return SDL_HITTEST_RESIZE_TOPRIGHT;
		case WindowHitTest::ResizeRight:
			return SDL_HITTEST_RESIZE_RIGHT;
		case WindowHitTest::ResizeBottomRight:
			return SDL_HITTEST_RESIZE_BOTTOMRIGHT;
		case WindowHitTest::ResizeBottom:
			return SDL_HITTEST_RESIZE_BOTTOM;
		case WindowHitTest::ResizeBottomLeft:
			return SDL_HITTEST_RESIZE_BOTTOMLEFT;
		case WindowHitTest::ResizeLeft:
			return SDL_HITTEST_RESIZE_LEFT;
		default:
			return SDL_HITTEST_NORMAL;
		}
	}, this);
}

#endif // WIDER_SDL2_SYSTEM