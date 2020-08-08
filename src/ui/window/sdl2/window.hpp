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

        void begin() override;
        void end() override;
    private:
        SDL_Window* window_ = nullptr;
        SDL_GLContext gl_context_ = nullptr;
    private:
        void configureGl(int x, int y, int w, int h);
        void initImgui();
        void stopImgui();
    };
}

#endif // WIDER_SDL2_SYSTEM

#endif // WINDOW_SDL2_HPP