#include "window.hpp"
#include <stdexcept>

#ifdef WIDER_SDL2_SYSTEM

#include <SDL2/SDL.h>
#include <glad/glad.h>
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

#endif // WIDER_SDL2_SYSTEM