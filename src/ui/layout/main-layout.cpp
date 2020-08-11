#include "main-layout.hpp"
#include "../window/common/window.hpp"

#include "imgui.h"
#include "imgui_internal.h"

using namespace wider::ui::layout;

MainLayout::MainLayout(wider::ui::window::Window* mainWindow, const wider::core::WiderApp &app) :
	app_(app), mainWindow_(mainWindow)
{

}

void MainLayout::draw()
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
	const auto &io = ImGui::GetIO();
	if (ImGui::IsMouseHoveringRect(min, max) && ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
		
	}

	ImGui::EndMainMenuBar();
}