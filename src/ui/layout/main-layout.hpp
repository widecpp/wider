#ifndef UI_LAYOUT_MAIN_LAYOUT_HPP
#define UI_LAYOUT_MAIN_LAYOUT_HPP

namespace wider
{
    namespace core
    {
        class WiderApp;
    }

    namespace ui
    {
        namespace window
        {
            class Window;
        }

        namespace layout
        {
            class MainLayout
            {
            public:
                MainLayout(wider::ui::window::Window* mainWindow, const wider::core::WiderApp &app);

                void draw();
            private:
                wider::ui::window::Window* const mainWindow_;
                const wider::core::WiderApp &app_;
            };
            
        }
    }
}

#endif // UI_LAYOUT_MAIN_LAYOUT_HPP