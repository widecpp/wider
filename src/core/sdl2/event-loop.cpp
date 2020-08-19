#include "event-loop.hpp"
#include "../common/app.hpp"

#ifdef WIDER_SDL2_SYSTEM
#include <SDL2/SDL.h>
#include "../../ui/window/sdl2/window.hpp"
#include "imgui_impl_sdl.h"

void wider::core::sdl2::handleEvents(WiderApp &app)
{
    SDL_Event event;
	int i = 1;
    if (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            app.onQuitRequested();
            break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WindowEventID::SDL_WINDOWEVENT_HIT_TEST:
				// TODO: [OOKAMI] Resize?
				auto* wnd = wider::ui::window::sdl2::Window::getById(event.window.windowID);
				SDL_Log("%i %i", event.window.data1, event.window.data2);
				break;
			}
			//SDL_Log("%i", event.window.event);
			break;
        default:
            break;
        }
    }
}

#endif // WIDER_SDL2_SYSTEM