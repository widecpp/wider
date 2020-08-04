#include "main.hpp"
#include "init.hpp"
#include "event-loop.hpp"

#ifdef WIDER_SDL2_SYSTEM
#include <SDL2/SDL.h>

#include "imgui.h"
#include "imgui_impl_sdl.h"

int main(int argc, char *argv[])
{
    if (!wider::core::sdl2::init())
        return 1;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    return wider::core::wider_main(argc, argv, &wider::core::sdl2::handleEvents);
}

#endif // WIDER_SDL2_SYSTEM