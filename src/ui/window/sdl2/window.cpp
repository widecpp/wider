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
}

Window::~Window()
{
    SDL_DestroyWindow(window_);
}

#endif // WIDER_SDL2_SYSTEM