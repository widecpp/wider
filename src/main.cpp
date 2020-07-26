#include <string>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    if( SDL_Init(0) != 0 )
    {
        return 1;
    }

    SDL_Surface* screen_surface = NULL;

    SDL_Window* window = NULL;

    window = SDL_CreateWindow("wIDEr",SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, 700, 700, 
    SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
    
    if (window == NULL) {
        return 1;
    }

	screen_surface = SDL_GetWindowSurface(window);

	SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0, 255, 0));

	SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}