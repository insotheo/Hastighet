#define HASTIGHET_ENGINE_GAME

#include<Hastighet.h>

class MyGameSandbox : public Hastighet::Application{
public:
    MyGameSandbox(){}
    ~MyGameSandbox(){}

};

Hastighet::Application* Hastighet::CreateApplication(){
    return new MyGameSandbox();
}