#include "Application.hpp"

#include<GLFW/glfw3.h>

namespace Hastighet{

#define BIND_EVENT_FUNC(fn) std::bind(&fn, this, std::placeholders::_1

    Application::Application() {
#ifdef _WIN32
        m_Window = std::unique_ptr<ApplicationWindow>(ApplicationWindow::Create(WindowProperties()));
        m_Window->SetEventCallback(BIND_EVENT_FUNC(Application::OnEvent)));
#endif
    }

    Application::~Application(){}

    void Application::Run(){
        while (m_IsRunning) {
            glClearColor(0, 1, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }

    void Application::OnEvent(Event& ev) {
        HASTIGHET_CORE_LOG_INFO(ev.ToString());
    }

}