#include "app.hpp"
using namespace wider::core;

WiderApp::WiderApp(int argc, char **argv) :
    args_({argc, argv})
{

}

void WiderApp::onQuitRequested()
{
    quitRequested_ = true;
}

bool WiderApp::quitRequested()
{
    return quitRequested_;
}