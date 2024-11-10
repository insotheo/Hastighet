//HE - Hastighet engine

#ifndef HE_CORE_H
#define HE_CORE_H

#ifndef _WIN32
    #error Hastighet engine supports only Windows!
#endif

#pragma comment(lib, "opengl32")

#ifdef HASTIGHET_ENGINE_GAME
    #define HASTIGHET_API __declspec(dllimport)
#else
    #define HASTIGHET_API __declspec(dllexport)
#endif

#define BIT(X) (1 << X)

#endif