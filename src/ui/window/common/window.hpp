#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>
#include <functional>
#include <utility>

#include "ui/window/common/window-data.hpp"

namespace wider
{
    namespace core
    {
        class WiderApp;
    }

    namespace ui::window
    {
        class Window
        {
        public:
            virtual ~Window() = default;

            // virtual void setHitTestCallback(std::function<WindowHitTest(int x, int y)> hitTest) = 0;
            
            virtual WindowSize getSize() const = 0;
            virtual void move(int x, int y) = 0;

            static std::unique_ptr<Window> create(wider::core::WiderApp &app, int w, int h);
        protected:
            Window(wider::core::WiderApp &app);
            void onInitialized();

            wider::core::WiderApp &app_;
        private:
            Window(const Window&) = delete;
        };
    }
    
}

#endif // WINDOW_HPP