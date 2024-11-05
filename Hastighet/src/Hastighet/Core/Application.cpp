#include "Application.hpp"

#include "Events/ApplicationEvents.hpp"
#include "Core/Log.hpp"

namespace Hastighet{

    Application::Application(){}
    Application::~Application(){}

    void Application::Run(){
        Hastighet::WindowResizeEvent e(1920, 1080);
        HASTIGHET_CORE_LOG_INFO(e.ToString());
        while (true);
    }

}