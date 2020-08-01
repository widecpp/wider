#include "window.hpp"
#ifdef WIDER_SDL2_SYSTEM
#include "../sdl2/window.hpp"
#endif
using namespace wider::ui::window;

std::unique_ptr<Window> Window::create(int w, int h)
{
    #ifdef WIDER_SDL2_SYSTEM
    return std::unique_ptr<Window>(new window::sdl2::Window(w, h));
    #endif
}