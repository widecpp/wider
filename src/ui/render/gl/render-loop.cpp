#include "render-loop.hpp"
#include "../../window/common/window.hpp"

#ifdef WIDER_SDL2_SYSTEM

#include <glad/glad.h>
#include <SDL2/SDL.h>
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

void wider::ui::render::gl::begin(wider::ui::window::Window *window)
{
    ImGui_ImplOpenGL3_NewFrame();
    window->begin();
    ImGui::NewFrame();
}

void wider::ui::render::gl::end(wider::ui::window::Window *window)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Render other stuff...
    // Render imgui
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    window->end();
}

#endif