#include "pch.h"

#include "ImGuiLayer.h"

#include "Hastighet/Core/Application.hpp"

#include <ImGui/imgui.h>
#include <ImGui/backends/imgui_impl_opengl3.h>

#include <GLFW/glfw3.h>

namespace Hastighet {

	ImGuiLayer::ImGuiLayer() : Layer("HE_ImGui_Layer") {}

	ImGuiLayer::~ImGuiLayer(){}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& imgio = ImGui::GetIO();
		imgio.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		imgio.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
	}

	void ImGuiLayer::OnUpdate()
	{
		Application& app = Application::Get();
		ImGuiIO& imgio = ImGui::GetIO();
		imgio.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		float dt = (float)glfwGetTime();
		imgio.DeltaTime = m_Time > 0.0f ? (dt - m_Time) : (1 / 60.f);
		m_Time = dt;

		static bool flag = true;
		ImGui::ShowDemoWindow(&flag);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{

	}

}