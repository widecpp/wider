#include "main.hpp"
#include <string>
#include "app.hpp"
#include "../../ui/window/common/window.hpp"

int wider::core::wider_main(int argc, char *argv[], void (*evCallback)(WiderApp &app))
{
    WiderApp app(argc, argv);
    auto window = wider::ui::window::Window::create(700, 700);

	auto *pWindow = window.get();

    while (!app.quitRequested())
    {
        evCallback(app);
    }
    return 0;
}