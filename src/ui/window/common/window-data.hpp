#ifndef WINDOW_DATA
#define WINDOW_DATA

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

    struct WindowSize
    {
        int width;
        int height;
    };
}

#endif // WINDOW_DATA


