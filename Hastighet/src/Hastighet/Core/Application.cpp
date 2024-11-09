#include "Application.hpp"

#include<GLFW/glfw3.h>

namespace Hastighet{

    Application::Application() {
#ifdef _WIN32
        m_Window = std::unique_ptr<ApplicationWindow>(ApplicationWindow::Create(WindowProperties()));
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

}