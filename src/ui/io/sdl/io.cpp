#include "io.hpp"

#ifdef WIDER_SDL2_SYSTEM
#include <SDL2/SDL.h>

void wider::ui::io::sdl::begin(Data &data)
{
	SDL_GetGlobalMouseState(&data.mouse.x, &data.mouse.y);
}

void wider::ui::io::sdl::end(Data &data)
{
}

#endif // WIDER_SDL2_SYSTEM