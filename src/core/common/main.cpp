#include "main.hpp"
#include <string>
#include "app.hpp"
#include "../../ui/window/common/window.hpp"
#include "../../ui/imgui/init.hpp"
#include "../../ui/render/common/render-loop.hpp"
#include "../../ui/layout/main-layout.hpp"
#include "../../ui/io/common/io.hpp"

int wider::core::wider_main(int argc, char *argv[], void (*evCallback)(WiderApp &app))
{
    WiderApp app(argc, argv);
    auto imguiContext = wider::ui::imgui::init();
    auto window = wider::ui::window::Window::create(700, 700);

	auto *pWindow = window.get();
	wider::ui::layout::MainLayout ml(pWindow, app);

	wider::ui::io::Data ioData;

    while (!app.quitRequested())
    {
        evCallback(app);
		
		wider::ui::io::common::begin(ioData);
        wider::ui::render::common::begin(pWindow);
        ml.draw(ioData);
        wider::ui::render::common::end(pWindow);
		wider::ui::io::common::end(ioData);
    }
    return 0;
}