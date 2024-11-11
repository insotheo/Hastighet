#include "Application.hpp"

#include "Log.hpp"

#include<glad/glad.h>

namespace Hastighet{

    Application* Application::s_Instance = nullptr;

    Application::Application() {
        if (!s_Instance) {
            HASTIGHET_CORE_LOG_ERROR("Application is already exists!");
            std::cerr << "Application is already exists!";
        }
        s_Instance = this;
        m_Window = std::unique_ptr<ApplicationWindow>(ApplicationWindow::Create(WindowProperties()));
        m_Window->SetEventCallback(BIND_EVENT_FUNC(Application::OnEvent)));
    }

    Application::~Application(){}

    void Application::Run(){
        while (m_IsRunning) {
            glClearColor(0.414f, 0.756f, 0.484f, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer* layer : m_LayerStack) {
                layer->OnUpdate();
            }

            m_Window->OnUpdate();
        }
    }

    void Application::OnEvent(Event& ev) {
        EventDispatcher dispatcher(ev);

        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(Application::OnWindowClose)));

        for (auto iter = m_LayerStack.end(); iter != m_LayerStack.begin();) {
            (*--iter)->OnEvent(ev);
            if (ev.IsHandled()) {
                break;
            }
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& event) {
        m_IsRunning = false;
        return true;
    }

    void Application::PushLayer(Layer* layer) {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* overlay) {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }

}