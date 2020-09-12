#include "core/common/app.hpp"
#include "ui/window/common/window.hpp"
#include "ui/layout/factory/layout-factory.hpp"

int main(int argc, char *argv[])
{
	auto app = wider::core::WiderApp::createApp(argc, argv);
	auto wnd = wider::ui::window::Window::create(*app.get(), 800, 600);
	auto mainLayout = wider::ui::layout::LayoutFactory::createMainLayout();
	wnd->applyLayout(mainLayout.get());
	return app->run(wnd.get());
}