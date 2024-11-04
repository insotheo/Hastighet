#ifndef HE_APPLICATION_HPP
#define HE_APPLICATION_HPP

#include "Core.h"

namespace Hastighet{

    class HASTIGHET_API Application{
    public:
        Application();
        virtual ~Application();

        void Run();

    };

    Application* CreateApplication();
}

#endif