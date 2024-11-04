#define HASTIGHET_ENGINE_GAME

#include<iostream>
#include<Hastighet.h>

class MyGameSandbox : public Hastighet::Application{
public:
    MyGameSandbox(){
        HASTIGHET_CLIENT_LOG_TRACE("Hello, World!");
    }
    ~MyGameSandbox(){}

};

Hastighet::Application* Hastighet::CreateApplication(){
    return new MyGameSandbox();
}