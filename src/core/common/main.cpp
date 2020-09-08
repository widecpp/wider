#include "main.hpp"
#include <string>
#include "app.hpp"
#include "../../ui/window/common/window.hpp"

int wider::core::wider_main_own_cycle(int argc, char *argv[], std::function<void(WiderApp &app)> evCallback)
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

int wider::core::wider_main_out_cycle(int argc, char *argv[], std::function<int(WiderApp &app)> runCallback)
{
	WiderApp app(argc, argv);
    auto window = wider::ui::window::Window::create(700, 700);

	auto *pWindow = window.get();

	return runCallback(app);
}