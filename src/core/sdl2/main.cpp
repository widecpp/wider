#include "main.hpp"
#include "init.hpp"

#ifdef WIDER_SDL2_SYSTEM
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    if (wider::core::sdl2::init() != 0)
        return 1;
    return wider::core::wider_main(argc, argv);
}

#endif // WIDER_SDL2_SYSTEM