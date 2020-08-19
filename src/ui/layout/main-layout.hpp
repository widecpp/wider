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
        namespace io
        {
            struct Data;
        }

        namespace window
        {
            class Window;
        }

        namespace layout
        {
            class MainLayout
            {
            public:
                MainLayout(wider::ui::window::Window* mainWindow, wider::core::WiderApp &app);

                void draw(const wider::ui::io::Data &ioData);
            private:
                wider::ui::window::Window* const mainWindow_;
                wider::core::WiderApp &app_;

                struct {
                    struct {
                        float minX, minY;
                        float maxX, maxY;
                    } draggable;
                } hitTestData_ = {};
            private:
                void initHitTest();
            };
            
        }
    }
}

#endif // UI_LAYOUT_MAIN_LAYOUT_HPP