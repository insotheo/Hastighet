#include "pch.h"

#include "ImGuiLayer.h"

#include "Hastighet/Core/Application.hpp"

#include <ImGui/imgui.h>
#include <ImGui/backends/imgui_impl_opengl3.h>
#include <ImGui/backends/imgui_impl_glfw.h>

#include "Hastighet/Core/Log.hpp"

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
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FUNC(ImGuiLayer::OnMouseButtonPressedEvent)));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FUNC(ImGuiLayer::OnMouseButtonReleasedEvent)));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FUNC(ImGuiLayer::OnMouseMovedEvent)));
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FUNC(ImGuiLayer::OnMouseScrolledEvent)));
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FUNC(ImGuiLayer::OnKeyPressedEvent)));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FUNC(ImGuiLayer::OnKeyReleasedEvent)));
		dispatcher.Dispatch<KeyTypedEvent>(BIND_EVENT_FUNC(ImGuiLayer::OnKeyTypedEvent)));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FUNC(ImGuiLayer::OnWindowResizedEvent)));
	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& event)
	{
		ImGuiIO& imgio = ImGui::GetIO();
		imgio.MouseDown[event.GetMouseButton()] = true;

		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event)
	{
		ImGuiIO& imgio = ImGui::GetIO();
		imgio.MouseDown[event.GetMouseButton()] = GLFW_RELEASE;

		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& event)
	{
		ImGuiIO& imgio = ImGui::GetIO();
		imgio.MousePos = ImVec2(event.GetX(), event.GetY());

		return false;
	}

	bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& event)
	{
		ImGuiIO& imgio = ImGui::GetIO();
		imgio.MouseWheel = event.GetYOffset();
		imgio.MouseWheelH = event.GetXOffset();

		return false;
	}

	bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& event)
	{
		ImGuiIO& imgio = ImGui::GetIO();
		imgio.AddKeyEvent(HASTIGHET_ENGINE_MACRO_IMGUI_KEY_TO_GLFW_KEY(event.GetKeyCode()), true);

		//TODO: Ctrl, Shift, etc

		return false;
	}

	bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& event)
	{
		ImGuiIO& imgio = ImGui::GetIO();
		imgio.AddKeyEvent(HASTIGHET_ENGINE_MACRO_IMGUI_KEY_TO_GLFW_KEY(event.GetKeyCode()), false);

		return false;
	}

	bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& event)
	{
		ImGuiIO& imgio = ImGui::GetIO();
		int keycode = (int)event.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000) {
			imgio.AddInputCharacter((unsigned int)keycode);
		}

		return false;
	}

	bool ImGuiLayer::OnWindowResizedEvent(WindowResizeEvent& event)
	{
		ImGuiIO& imgio = ImGui::GetIO();
		imgio.DisplaySize = ImVec2(event.GetWidth(), event.GetHeight());
		imgio.DisplayFramebufferScale = ImVec2(1.f, 1.f);

		return false;
	}

}