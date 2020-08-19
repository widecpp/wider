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
		constexpr auto tolerance = 3;
		auto [w, h] = mainWindow_->getSize();
		wider::ui::window::WindowHitTest hitTest = wider::ui::window::WindowHitTest::Normal;
		if (x >= 0 && x <= tolerance)
			hitTest = hitTest | wider::ui::window::WindowHitTest::ResizeLeft;
		if (y >= 0 && y <= tolerance)
			hitTest = hitTest | wider::ui::window::WindowHitTest::ResizeTop;
		if (x >= w - tolerance && x <= w)
			hitTest = hitTest | wider::ui::window::WindowHitTest::ResizeRight;
		if (y >= h - tolerance && y <= h)
			hitTest = hitTest | wider::ui::window::WindowHitTest::ResizeBottom;
		if (hitTest != wider::ui::window::WindowHitTest::Normal)
			return hitTest;

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
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, {4.f, 8.f});
    ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("File"))
	{
		// Placeholders
		ImGui::MenuItem("New");
		ImGui::MenuItem("Open");
		ImGui::MenuItem("Save");

		ImGui::Separator();
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
	ImGui::PopStyleVar();
}