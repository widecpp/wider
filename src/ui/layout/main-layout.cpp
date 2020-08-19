#include "main-layout.hpp"
#include "../window/common/window.hpp"
#include "../io/data.hpp"

#include "../../core/common/app.hpp"

#include "imgui.h"
#include "imgui_internal.h"

using namespace wider::ui::layout;

MainLayout::MainLayout(wider::ui::window::Window* mainWindow, wider::core::WiderApp &app) :
	app_(app), mainWindow_(mainWindow)
{
	mainWindow_->setHitTestCallback([this](int x, int y) -> wider::ui::window::WindowHitTest
	{
		if (x >= hitTestData_.draggable.minX && x <= hitTestData_.draggable.maxX &&
			y >= hitTestData_.draggable.minY && y <= hitTestData_.draggable.maxY)
		{
			return wider::ui::window::WindowHitTest::Draggable;
		}
		return wider::ui::window::WindowHitTest::Normal;
	});
}

void MainLayout::draw(const wider::ui::io::Data &ioData)
{ 
    ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("File"))
	{
		if (ImGui::MenuItem("Exit")) {
			app_.onQuitRequested();
		}
		ImGui::EndMenu();
	}
	ImGui::Separator();
	auto* window = ImGui::GetCurrentWindow();
	auto cur = window->DC.CursorPos;
	auto width = window->Size.x - cur.x;
	auto lineSize = window->DC.CurrLineSize;
	ImVec2 min = cur, max { cur.x + width, lineSize.y };
	hitTestData_.draggable.minX = min.x;
	hitTestData_.draggable.minY = min.y;
	hitTestData_.draggable.maxX = max.x;
	hitTestData_.draggable.maxY = max.y;
	ImGui::EndMainMenuBar();
}