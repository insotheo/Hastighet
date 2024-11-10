#include "Application.hpp"

#include<GLFW/glfw3.h>

namespace Hastighet{

#define BIND_EVENT_FUNC(fn) std::bind(&fn, this, std::placeholders::_1

    Application::Application() {
        m_Window = std::unique_ptr<ApplicationWindow>(ApplicationWindow::Create(WindowProperties()));
        m_Window->SetEventCallback(BIND_EVENT_FUNC(Application::OnEvent)));
    }

    Application::~Application(){}

    void Application::Run(){
        while (m_IsRunning) {
            glClearColor(0, 1, 0, 1);
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
    }

    void Application::PushOverlay(Layer* overlay) {
        m_LayerStack.PushOverlay(overlay);
    }

}