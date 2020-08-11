#include "io.hpp"

#ifdef WIDER_SDL2_SYSTEM
#include <SDL2/SDL.h>

void wider::ui::io::sdl::begin(Data &data)
{
	auto state = SDL_GetGlobalMouseState(&data.mouse.x, &data.mouse.y);
	data.mouse.left = state & SDL_BUTTON(SDL_BUTTON_LEFT);
	data.mouse.right = state & SDL_BUTTON(SDL_BUTTON_RIGHT);
	data.mouse.middle = state & SDL_BUTTON(SDL_BUTTON_MIDDLE);
}

void wider::ui::io::sdl::end(Data &data)
{
}

#endif // WIDER_SDL2_SYSTEM