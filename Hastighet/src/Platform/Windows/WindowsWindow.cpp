#include "../pch.h"
#include "WindowsWindow.hpp"

namespace Hastighet {

	static bool s_GLFWInit = false;

	ApplicationWindow* ApplicationWindow::Create(const WindowProperties& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Finish();
	}

	void WindowsWindow::Init(const WindowProperties& props) {
		m_Data.WindowWidth = props.WindowWidth;
		m_Data.WindowHeight = props.WindowHeight;
		m_Data.WindowTitle = props.WindowTitle;

		if (!s_GLFWInit) {

			int success = glfwInit();
			s_GLFWInit = success == GLFW_TRUE ? true : false;
		}

		if (s_GLFWInit) {

			m_Window = glfwCreateWindow((int)props.WindowWidth, (int)props.WindowHeight, m_Data.WindowTitle.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, &m_Data);
		}
	}

	void WindowsWindow::Finish() {
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool state) {
		if (state) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}
		m_Data.WindowVSync = state;
	}

	bool WindowsWindow::IsVSync() const {
		return m_Data.WindowVSync;
	}

}