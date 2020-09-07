#ifndef WINDOW_GTK
#define WINDOW_GTK

#include "ui/window/common/window.hpp"

namespace wider::ui::window
{
    class WindowGtk :
        public Window
    {
    public:
        WindowGtk(int width, int height);

        WindowSize getSize() const override;
        void move(int x, int y) override;
    };
}

#endif // WINDOW_GTK
