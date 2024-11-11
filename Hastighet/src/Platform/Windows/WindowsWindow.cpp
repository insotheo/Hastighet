#include "pch.h"

#include "WindowsWindow.hpp"

#include "Hastighet/Core/Log.hpp"

#include "Hastighet/Events/Event.hpp"
#include "Hastighet/Events/ApplicationEvents.hpp"
#include "Hastighet/Events/KeyEvent.hpp"
#include "Hastighet/Events/MouseEvent.hpp"

#include <glad/glad.h>

namespace Hastighet {

	static bool s_GLFWInit = false;

	static void GLFWErrorCallback(int errCode, const char* msg) {
		std::stringstream stream;
		stream << "GLFW Error(" << errCode << "): \"" << msg << "\"";
		HASTIGHET_CORE_LOG_ERROR(stream.str());
	}

#ifdef _WIN32
	ApplicationWindow* ApplicationWindow::Create(const WindowProperties& props) {
		return new WindowsWindow(props);
	}
#endif // Windows

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
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInit = success == GLFW_TRUE ? true : false;
		}

		if (s_GLFWInit) {

			m_Window = glfwCreateWindow((int)props.WindowWidth, (int)props.WindowHeight, m_Data.WindowTitle.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(m_Window);

			int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
			if (status == GLFW_FALSE) {
				HASTIGHET_CORE_LOG_ERROR("Failed to init Glad!");
				std::cerr << "Failed to init Glad!";
			}

			glfwSetWindowUserPointer(m_Window, &m_Data);

			//Callbacks
			glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int w, int h) { //resizing
				WindowsData& data = *(WindowsData*)(glfwGetWindowUserPointer(window));
				data.WindowWidth = (unsigned int)w;
				data.WindowHeight = (unsigned int)h;
				WindowResizeEvent ev(w, h);
				data.WindowCallback(ev);
			});

			glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) { //closing
				WindowsData& data = *(WindowsData*)(glfwGetWindowUserPointer(window));
				WindowCloseEvent ev;
				data.WindowCallback(ev);
			});

			glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) { //keys
				WindowsData& data = *(WindowsData*)(glfwGetWindowUserPointer(window));
				int keycode = key;
				switch (action)
				{

				case GLFW_PRESS:
				{
					KeyPressedEvent ev(keycode, 0);
					data.WindowCallback(ev);
					break;
				}
				
				case GLFW_RELEASE:
				{
					KeyReleasedEvent ev(keycode);
					data.WindowCallback(ev);
					break;
				}

				case GLFW_REPEAT:
				{
					KeyPressedEvent ev(keycode, 1);
					data.WindowCallback(ev);
					break;
				}

				}
			});

			glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode) {
				WindowsData& data = *(WindowsData*)(glfwGetWindowUserPointer(window));
				KeyTypedEvent ev(keycode);
				data.WindowCallback(ev);
			});

			glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) { //buttons
				WindowsData& data = *(WindowsData*)(glfwGetWindowUserPointer(window));
				int buttoncode = button;
				switch (action)
				{

				case GLFW_PRESS:
				{
					MouseButtonPressedEvent ev(buttoncode);
					data.WindowCallback(ev);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent ev(buttoncode);
					data.WindowCallback(ev);
					break;
				}

				}
			});

			glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y) { //mouse pos
				WindowsData& data = *(WindowsData*)(glfwGetWindowUserPointer(window));
				MouseMovedEvent ev((float)x, (float)y);
				data.WindowCallback(ev);
			});

			glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOff, double yOff) { //mouse movement
				WindowsData& data = *(WindowsData*)(glfwGetWindowUserPointer(window));
				MouseScrolledEvent ev((float)xOff, (float)yOff);
				data.WindowCallback(ev);
			});

			glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused) { // window focus
				WindowsData& data = *(WindowsData*)(glfwGetWindowUserPointer(window));
				if (focused == GLFW_TRUE) {
					WindowGotFocusEvent ev;
					data.WindowCallback(ev);
				}
				else {
					WindowLostFocusEvent ev;
					data.WindowCallback(ev);
				}
			});

			glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int x, int y) { //window movement
				WindowsData& data = *(WindowsData*)(glfwGetWindowUserPointer(window));
				WindowMovedEvent ev((unsigned int)x, (unsigned int)y);
				data.WindowCallback(ev);
			});
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