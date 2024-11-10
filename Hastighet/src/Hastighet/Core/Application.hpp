#ifndef HE_APPLICATION_HPP
#define HE_APPLICATION_HPP

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"

#include "Hastighet/Events/Event.hpp"
#include "Hastighet/Events/ApplicationEvents.hpp"

namespace Hastighet{

    class HASTIGHET_API Application{
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& ev);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        inline ApplicationWindow& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }
    private:
        bool OnWindowClose(WindowCloseEvent& event);
        std::unique_ptr<ApplicationWindow> m_Window;
        bool m_IsRunning = true;
        LayerStack m_LayerStack;
        static Application* s_Instance;
    };

    Application* CreateApplication();
}

#endif