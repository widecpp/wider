#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>

namespace wider::ui::window
{
    class Window
    {
    public:
        virtual ~Window() = default;
        static std::unique_ptr<Window> create(int w, int h);
    protected:
        Window() = default;
    private:
        Window(const Window&) = delete;
    };
}

#endif // WINDOW_HPP