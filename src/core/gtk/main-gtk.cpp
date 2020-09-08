#include "main-gtk.hpp"
#include "core/common/main.hpp"
#include "core/common/app.hpp"
#include <gtkmm/application.h>
#include <gtkmm/window.h>

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.widecpp.wider.wider");
	return wider::core::wider_main_out_cycle(argc, argv, [&app](wider::core::WiderApp &widerApp)
	{
		return app->run();
	});
}