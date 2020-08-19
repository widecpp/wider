#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>
#include <functional>

namespace wider::ui::window
{
    enum class WindowHitTest
    {
        Normal,
        Draggable,
        ResizeTopLeft,
        ResizeTop,
        ResizeTopRight,
        ResizeRight,
        ResizeBottomRight,
        ResizeBottom,
        ResizeBottomLeft,
        ResizeLeft,
    };

    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void begin() = 0;
        virtual void end() = 0;

        virtual void setHitTestCallback(std::function<WindowHitTest(int x, int y)> hitTest) = 0;
        
        virtual void move(float x, float y) = 0;

        static std::unique_ptr<Window> create(int w, int h);
    protected:
        Window() = default;
    private:
        Window(const Window&) = delete;
    };
}

#endif // WINDOW_HPP