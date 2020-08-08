#include "init.hpp"

std::unique_ptr<wider::ui::imgui::Context> wider::ui::imgui::init()
{
    return std::make_unique<wider::ui::imgui::Context>();
}