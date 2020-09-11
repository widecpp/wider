#include "core/common/app.hpp"
#include "ui/window/common/window.hpp"

int main(int argc, char *argv[])
{
	auto app = wider::core::WiderApp::createApp(argc, argv);
	auto wnd = wider::ui::window::Window::create(*app.get(), 800, 600);
	return app->run();
}