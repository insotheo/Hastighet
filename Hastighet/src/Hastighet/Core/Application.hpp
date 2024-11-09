#ifndef HE_APPLICATION_HPP
#define HE_APPLICATION_HPP

#include "Core.h"
#include "Window.h"

namespace Hastighet{

    class HASTIGHET_API Application{
    public:
        Application();
        virtual ~Application();

        void Run();
    private:
        std::unique_ptr<ApplicationWindow> m_Window;
        bool m_IsRunning = true;
    };

    Application* CreateApplication();
}

#endif