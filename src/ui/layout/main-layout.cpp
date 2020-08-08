#include "main-layout.hpp"
#include "../window/common/window.hpp"

#include "imgui.h"
#include "imgui_internal.h"


void wider::ui::layout::draw(wider::ui::window::Window* mainWindow)
{
    ImGui::BeginMainMenuBar();
	/*if (ImGui::BeginMenu("File"))
	{
		ImGui::EndMenu();
	}*/
	ImGui::Separator();
	//ImGui::Text("Nice");
	auto* window = ImGui::GetCurrentWindow();
	auto cur = window->DC.CursorPos;
	auto width = window->Size.x - cur.x;
	auto lineSize = window->DC.CurrLineSize;
	ImVec2 min = cur, max { cur.x + width, lineSize.y };
	if (ImGui::IsMouseHoveringRect(min, max) && ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
		const auto &io = ImGui::GetIO();
		auto delta = io.MouseDelta;
		ImGui::Text("Nice %f %f", delta.x, delta.y);
        // ouch...
		mainWindow->move(delta.x, delta.y);
	}
}