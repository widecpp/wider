#ifndef UI_RENDER_GL_RENDER_LOOP_HPP
#define UI_RENDER_GL_RENDER_LOOP_HPP

#ifdef WIDER_SDL2_SYSTEM
namespace wider::ui
{
    namespace window
    {
        class Window;
    }

    namespace render::gl
    {
        void begin(wider::ui::window::Window *window);
        void end(wider::ui::window::Window *window);
    }
}
#endif

#endif // UI_RENDER_GL_RENDER_LOOP_HPP