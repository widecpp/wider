#ifndef APP_GTK
#define APP_GTK

#include "core/common/app.hpp"
#include <memory>

namespace wider::core
{
    class AppGtk :
        public WiderApp
    {
    public:
        AppGtk(int argc, char **argv);
        ~AppGtk();

        int run() override;
        void onWindowAdded(wider::ui::window::Window *wnd) override;
    private:
        AppGtk(const AppGtk &) = delete;
    private:
        struct AppImpl;
        std::unique_ptr<AppImpl> impl_;
    };
}

#endif // APP_GTK
