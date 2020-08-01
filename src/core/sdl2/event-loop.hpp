#ifndef EVENT_LOOP_SDL2_HPP
#define EVENT_LOOP_SDL2_HPP

#ifdef WIDER_SDL2_SYSTEM
namespace wider::core
{
    class WiderApp;

    namespace sdl2
    {
        void handleEvents(WiderApp &app);
    }
}

#endif // WIDER_SDL2_SYSTEM

#endif // EVENT_LOOP_SDL2_HPP