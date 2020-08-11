#include "main-layout.hpp"
#include "../window/common/window.hpp"
#include "../io/data.hpp"

#include "imgui.h"
#include "imgui_internal.h"

using namespace wider::ui::layout;

MainLayout::MainLayout(wider::ui::window::Window* mainWindow, const wider::core::WiderApp &app) :
	app_(app), mainWindow_(mainWindow)
{

}

void MainLayout::draw(const wider::ui::io::Data &ioData)
{ 
    ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("File"))
	{
		ImGui::EndMenu();
	}
	ImGui::Separator();
	auto* window = ImGui::GetCurrentWindow();
	auto cur = window->DC.CursorPos;
	auto width = window->Size.x - cur.x;
	auto lineSize = window->DC.CurrLineSize;
	ImVec2 min = cur, max { cur.x + width, lineSize.y };
	if (ImGui::IsMouseDown(ImGuiMouseButton_Left))
	{
		if (doMoveWindow_) {
			auto dX = ioData.mouse.x - prevX_;
			auto dY = ioData.mouse.y - prevY_;
			mainWindow_->move(dX, dY);
			prevX_ = ioData.mouse.x;
			prevY_ = ioData.mouse.y;
		}
		if (ImGui::IsMouseHoveringRect(min, max)) {
			prevX_ = ioData.mouse.x;
			prevY_ = ioData.mouse.y;
			doMoveWindow_ = true;
		} 
	}
	else {
		doMoveWindow_ = false;
	}

	ImGui::EndMainMenuBar();
}