#ifndef APP_HPP
#define APP_HPP

#include <memory>

namespace wider::ui::window
{
    class Window;
}

namespace wider::core
{
    class WiderApp
    {
    public:
        virtual int run(wider::ui::window::Window *wnd) = 0;
        virtual void onWindowAdded(wider::ui::window::Window *wnd) = 0;

        static std::unique_ptr<WiderApp> createApp(int argc, char **argv);
    protected:
        WiderApp(int argc, char **argv);
        void initApp();

        struct {
            int argc;
            char **argv;
        } const args_;
    private:
        WiderApp(const WiderApp &) = delete;
    };
}

#endif // APP_HPP