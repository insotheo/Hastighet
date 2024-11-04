#ifndef HE_ENTRY_POINT_HPP
#define HE_ENTRY_POINT_HPP

#ifdef _WIN32

extern Hastighet::Application* Hastighet::CreateApplication();

int main(int argc, char** argv){
    Hastighet::Application* app = Hastighet::CreateApplication();
    app->Run();
    delete app;
}

#endif

#endif