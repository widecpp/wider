#include "init.hpp"

#ifdef WIDER_SDL2_SYSTEM
#include <SDL2/SDL.h>
#include "../../ui/render/gl/gl-init.hpp"
bool wider::core::sdl2::init()
{
    const auto initCode = SDL_Init(SDL_INIT_VIDEO);
    if (initCode != 0)
        return false;
    
    wider::ui::render::prepareOpenGl();
    
    return true;
}

#endif // WIDER_SDL2_SYSTEM