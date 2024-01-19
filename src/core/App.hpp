#ifndef __APP_H_LQ6T8D6VPIS0__
#define __APP_H_LQ6T8D6VPIS0__

#ifdef MSVC
#include <Windows.h>
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include <core/Gui.hpp>
// #include <core/keyboard.hpp>
// #include <core/mouse.hpp>

#include <chrono>
#include <string>
#include <thread>

class Gui;

class App
{
public:
    App(const char *windowTitle, const int &windowWidth, const int &windowHeight);
    ~App();
    GLFWwindow *GetWindow();
    bool GetControlled() const;
    void Begin();
    void Update();
    void End();

private:
    void Init();

private:
    GLFWwindow *window;
    Gui *gui;
    std::string windowTitle;
    int windowWidth, windowHeight, bufferWidth, bufferHeight;

private:
    bool showFpsInWindowTitle;
    unsigned int targetfps;
    long double lastUpdateTime, lastFrameTime, currentTime, deltaTime;
};

#endif // __APP_H_LQ6T8D6VPIS0__
