#ifndef WINDOW_SDL2_HPP
#define WINDOW_SDL2_HPP

#include "../common/window.hpp"

#ifdef WIDER_SDL2_SYSTEM
#include <SDL2/SDL.h>

namespace wider::ui::window::sdl2
{
    class Window :
        public window::Window
    {
    public:
        Window(int w, int h);
        ~Window();
    private:
        SDL_Window* window_ = nullptr;
        SDL_GLContext gl_context_ = nullptr;
    };
}

#endif // WIDER_SDL2_SYSTEM

#endif // WINDOW_SDL2_HPP