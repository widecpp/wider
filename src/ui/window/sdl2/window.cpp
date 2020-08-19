#include "window.hpp"
#include <stdexcept>

#ifdef WIDER_SDL2_SYSTEM

using namespace wider::ui::window::sdl2;

Window::Window(int w, int h)
{
    const auto flags = 
        SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_RESIZABLE | // window flags
        SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI; // graphics flags
    window_ = SDL_CreateWindow("wIDEr",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        w, h, 
        flags);
    if (!window_)
        throw std::runtime_error("Unable to create window!");
    configureGl(0, 0, w, h);
    initImgui();
}

Window::~Window()
{
    stopImgui();
    SDL_DestroyWindow(window_);
}

void Window::move(float x, float y)
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
		// TODO: [OOKAMI] Make resize;
		default:
			return SDL_HITTEST_NORMAL;
		}
	}, this);
}

#endif // WIDER_SDL2_SYSTEM