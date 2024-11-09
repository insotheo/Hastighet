#ifndef HE_APPLICATION_HPP
#define HE_APPLICATION_HPP

#include "Core.h"
#include "Events/Event.hpp"
#include "Events/ApplicationEvents.hpp"
#include "Log.hpp"
#include "Window.h"

namespace Hastighet{

    class HASTIGHET_API Application{
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& ev);
    private:
        bool OnWindowClose(WindowCloseEvent& event);
        std::unique_ptr<ApplicationWindow> m_Window;
        bool m_IsRunning = true;
    };

    Application* CreateApplication();
}

#endif