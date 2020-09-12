#include "layout-factory.hpp"
#include "ui/layout/main/main-layout.hpp"
using namespace wider::ui::layout;

std::shared_ptr<Layout> LayoutFactory::createMainLayout()
{
    return std::make_shared<MainLayout>();
}