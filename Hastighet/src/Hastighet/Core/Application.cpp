#include "Application.hpp"

#include "Events/ApplicationEvents.hpp"
#include "Core/Log.hpp"

namespace Hastighet{

    Application::Application(){}
    Application::~Application(){}

    void Application::Run(){
        Hastighet::WindowResizeEvent e(1280, 720);
        HASTIGHET_CORE_LOG_INFO(e.ToString());
        while (true);
    }

}