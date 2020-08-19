#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>
#include <functional>
#include <utility>
#include <stdint.h>

namespace wider::ui::window
{
    enum class WindowHitTest : uint8_t
    {
        Normal = 0,
        Draggable = 0xff,
        
        ResizeTop = 0x01,
        ResizeBottom = 0x02,
        ResizeLeft = 0x04,
        ResizeRight = 0x08,
        
        ResizeTopLeft = ResizeTop | ResizeLeft,
        ResizeTopRight = ResizeTop | ResizeRight,
        ResizeBottomLeft = ResizeBottom | ResizeLeft,
        ResizeBottomRight = ResizeBottom | ResizeRight,
    };

    constexpr WindowHitTest operator|(WindowHitTest left, WindowHitTest right)
    {
        return static_cast<WindowHitTest>(static_cast<uint8_t>(left) | static_cast<uint8_t>(right));
    }

    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void begin() = 0;
        virtual void end() = 0;

        virtual void setHitTestCallback(std::function<WindowHitTest(int x, int y)> hitTest) = 0;
        
        virtual std::pair<int, int> getSize() = 0;
        virtual void move(float x, float y) = 0;

        static std::unique_ptr<Window> create(int w, int h);
    protected:
        Window() = default;
    private:
        Window(const Window&) = delete;
    };
}

#endif // WINDOW_HPP