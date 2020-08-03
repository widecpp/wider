#include "event-loop.hpp"
#include "../common/app.hpp"

#ifdef WIDER_SDL2_SYSTEM
#include <SDL2/SDL.h>

void wider::core::sdl2::handleEvents(WiderApp &app)
{
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            app.onQuitRequested();
            break;
        
        default:
            break;
        }
    }
}

#endif // WIDER_SDL2_SYSTEM