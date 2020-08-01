#include "window.hpp"
#include <stdexcept>

#ifdef WIDER_SDL2_SYSTEM

using namespace wider::ui::window::sdl2;

Window::Window(int w, int h)
{
    window_ = SDL_CreateWindow("wIDEr",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        w, h, 
        SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
    if (!window_)
        throw std::runtime_error("Unable to create window!");
}

Window::~Window()
{
    SDL_DestroyWindow(window_);
}

#endif // WIDER_SDL2_SYSTEM