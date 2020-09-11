#ifndef WINDOW_GTK
#define WINDOW_GTK

#include "ui/window/common/window.hpp"
#include <memory>

namespace wider::ui::window
{
    class WindowGtk :
        public Window
    {
    public:
        WindowGtk(wider::core::WiderApp &app, int width, int height);
        ~WindowGtk();

        WindowSize getSize() const override;
        void move(int x, int y) override;

        void *getHandle();
    private:
        struct Impl;
        std::unique_ptr<Impl> impl_;
    };
}

#endif // WINDOW_GTK
