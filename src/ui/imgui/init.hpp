#ifndef UI_IMGUI_HPP
#define UI_IMGUI_HPP

#include <memory>
#include "context.hpp"

namespace wider::ui::imgui
{
    std::unique_ptr<wider::ui::imgui::Context> init();
}

#endif // UI_IMGUI_HPP