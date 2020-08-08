#include "window.hpp"
#include <stdexcept>

#ifdef WIDER_SDL2_SYSTEM

#include <SDL2/SDL.h>
#include <glad/glad.h>
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
using namespace wider::ui::window::sdl2;

void Window::configureGl(int x, int y, int w, int h)
{
	gl_context_ = SDL_GL_CreateContext(window_);
	SDL_GL_MakeCurrent(window_, gl_context_);

	SDL_GL_SetSwapInterval(1);
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		throw std::runtime_error("Unable to create window!");
	}
	if (!gladLoadGL()) {
		throw std::runtime_error("Unable to create window!");
	}
    glViewport(x, y, w, h);
}

void Window::initImgui()
{
	ImGui_ImplSDL2_InitForOpenGL(window_, gl_context_);
    ImGui_ImplOpenGL3_Init();
}

void Window::stopImgui()
{
	ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
}

void Window::begin()
{
	ImGui_ImplSDL2_NewFrame(window_);
}

void Window::end()
{
	SDL_GL_SwapWindow(window_);
}

#endif // WIDER_SDL2_SYSTEM