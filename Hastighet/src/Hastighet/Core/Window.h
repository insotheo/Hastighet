#ifndef HE_WINDOW_H
#define HE_WINDOW_H

#include "../pch.h"

#include<functional>

#include "Core.h"
#include "Events/Event.hpp"

namespace Hastighet {

	struct WindowProperties
	{
		std::string WindowTitle;
		unsigned int WindowHeight;
		unsigned int WindowWidth;

		WindowProperties(const std::string& title = "Hastighet game window",
			unsigned int width = 800,
			unsigned int height = 600) : WindowTitle(title), WindowWidth(width), WindowHeight(height){}

	};

	class HASTIGHET_API ApplicationWindow {
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~ApplicationWindow(){}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		
		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool state) = 0;
		virtual bool IsVSync() const = 0;

		static ApplicationWindow* Create(const WindowProperties& props = WindowProperties());
	};

}

#endif // !HE_WINDOW_H