#include "render-loop.hpp"
#include "../gl/render-loop.hpp"

void wider::ui::render::common::begin(wider::ui::window::Window *window)
{
    #ifdef WIDER_SDL2_SYSTEM
    wider::ui::render::gl::begin(window);
    #endif
}

void wider::ui::render::common::end(wider::ui::window::Window *window)
{
    #ifdef WIDER_SDL2_SYSTEM
    wider::ui::render::gl::end(window);
    #endif
}