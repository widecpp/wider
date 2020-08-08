#ifndef UI_RENDER_COMMON_RENDER_LOOP_HPP
#define UI_RENDER_COMMON_RENDER_LOOP_HPP

namespace wider::ui
{
    namespace window
    {
        class Window;
    }

    namespace render::common
    {
        void begin(wider::ui::window::Window *window);
        void end(wider::ui::window::Window *window);
    }
    
}

#endif // UI_RENDER_COMMON_RENDER_LOOP_HPP