#define HASTIGHET_ENGINE_GAME

#include<Hastighet.h>

class TestLayer : public Hastighet::Layer {
public:
    TestLayer() : Layer("TEST"){}

    void OnUpdate() override {
        
    }
    
    void OnEvent(Hastighet::Event& ev) override {
    }

};


class MyGameSandbox : public Hastighet::Application{
public:
    MyGameSandbox() {
        PushLayer(new TestLayer());
        PushOverlay(new Hastighet::ImGuiLayer());
    }

    ~MyGameSandbox(){}

};

Hastighet::Application* Hastighet::CreateApplication(){
    return new MyGameSandbox();
}