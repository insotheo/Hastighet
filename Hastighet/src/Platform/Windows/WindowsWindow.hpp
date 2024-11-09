#ifndef HE_WINDOWS_WINDOW_HPP
#define HE_WINDOWS_WINDOW_HPP

#include "Core/Window.h"

#include <GLFW/glfw3.h>

namespace Hastighet {

	class WindowsWindow : public ApplicationWindow {
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.WindowWidth; };
		inline unsigned int GetHeight() const override { return m_Data.WindowHeight; };

		inline void SetEventCallback(const EventCallbackFunc& callback) override { m_Data.WindowCallback = callback; };
		void SetVSync(bool state) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProperties& props);
		virtual void Finish();
	protected:
		GLFWwindow* m_Window;

		struct WindowsData
		{
			std::string WindowTitle;
			unsigned int WindowWidth, WindowHeight;
			bool WindowVSync;
			EventCallbackFunc WindowCallback;
		};

		WindowsData m_Data;
	};

}

#endif // !HE_WINDOWS_WINDOW_HPP
