#ifndef UI_IMGUI_CONTEXT_HPP
#define UI_IMGUI_CONTEXT_HPP

#include "imgui.h"

namespace wider::ui::imgui
{
    class Context
    {
    public:
        const ImGuiIO &io;
    public:
        Context();
        ~Context();
    private:
        ImGuiIO &prepare();
    };
}

#endif // UI_IMGUI_CONTEXT_HPP