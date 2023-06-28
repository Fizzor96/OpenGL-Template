#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#ifdef MSVC
#include <Windows.h>
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include <core/appgui.hpp>
#include <core/keyboard.hpp>
#include <core/mouse.hpp>

#include <primitives/triangle.hpp>

#include <chrono>
#include <string>

class AppGui;

class Application
{
public:
    static Application *Create(const char *windowTitle, const int &windowWidth, const int &windowHeight);
    static Application *GetCurrentApplication();

public:
    void Run();
    void Terminate();
    void ToggleFullScreen();
    void MaximizeWindow();
    void MinimizeWindow();
    GLFWwindow *getCurrentContext();
    void SetFrameRate(unsigned int fps);
    void Toggle_ShowFPSInTitle();
    int GetCurrentFPS() const;

private:
    static Application *currentApplication;
    Application(const char *windowTitle, const int &windowWidth, const int &windowHeight);
    ~Application();

private:
    void draw();
    void update();
    void initCustomObjects();

private:
    void initialize();
    void createWindow();
    void setupContext();
    void initializeGLEW();
    void initializeGLFW();
    void initializeInput();
    void initFpsRelatedVars();
    void setViewport();
    void cleanup();
    static void framebufferSizeCallback(GLFWwindow *window, int width, int height);

private:
    Triangle *triangle;
    AppGui *appgui;

private:
    GLFWwindow *window;
    std::string windowTitle;
    int windowWidth, windowHeight, bufferWidth, bufferHeight;

private:
    bool showFpsInWindowTitle;
    unsigned int targetfps, fps;
    double fpsToleranceLimitMultiplyer;
    std::chrono::high_resolution_clock::time_point previousTime, currentTime;
    long double targetFrameTime, deltaTime;
};

#endif // __APPLICATION_H__