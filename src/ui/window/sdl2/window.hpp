#ifndef WINDOW_SDL2_HPP
#define WINDOW_SDL2_HPP

#include "../common/window.hpp"
#include <functional>

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

        void setHitTestCallback(std::function<WindowHitTest(int x, int y)> hitTest) override;

        void move(float x, float y) override;
    private:
        SDL_Window* window_ = nullptr;
        SDL_GLContext gl_context_ = nullptr;
        std::function<WindowHitTest(int x, int y)> hitTest_;
    private:
        void configureGl(int x, int y, int w, int h);
        void initImgui();
        void stopImgui();
    };
}

#endif // WIDER_SDL2_SYSTEM

#endif // WINDOW_SDL2_HPP