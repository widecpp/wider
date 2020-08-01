#include "init.hpp"

#ifdef WIDER_SDL2_SYSTEM
#include <SDL2/SDL.h>

int wider::core::sdl2::init()
{
    return SDL_Init(0);
}

#endif // WIDER_SDL2_SYSTEM