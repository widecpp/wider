#include "context.hpp"
using namespace wider::ui::imgui;

Context::Context(): io(prepare())
{
    // TODO: [OOKAMI] Перенести куда-нибудь
    ImGui::StyleColorsDark();
}

Context::~Context()
{
    ImGui::DestroyContext();
}

ImGuiIO &Context::prepare()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    return io;
}