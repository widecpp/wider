#include "app.hpp"
#include "core/gtk/app-gtk.hpp"

using namespace wider::core;

WiderApp::WiderApp(int argc, char **argv) :
    args_({argc, argv})
{

}

std::unique_ptr<WiderApp> WiderApp::createApp(int argc, char **argv)
{
	return std::make_unique<AppGtk>(argc, argv);
}

void WiderApp::initApp()
{

}