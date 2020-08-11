#include "main.hpp"
#include <string>
#include "app.hpp"
#include "../../ui/window/common/window.hpp"
#include "../../ui/imgui/init.hpp"
#include "../../ui/render/common/render-loop.hpp"
#include "../../ui/layout/main-layout.hpp"

int wider::core::wider_main(int argc, char *argv[], void (*evCallback)(WiderApp &app))
{
    WiderApp app(argc, argv);
    auto imguiContext = wider::ui::imgui::init();
    auto window = wider::ui::window::Window::create(700, 700);

	auto *pWindow = window.get();
	wider::ui::layout::MainLayout ml(app, pWindow);
    while (!app.quitRequested())
    {
        evCallback(app);

        wider::ui::render::common::begin(pWindow);
        ml.draw();
        wider::ui::render::common::end(pWindow);
    }
    return 0;
}