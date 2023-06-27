#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#ifdef MSVC
#include <Windows.h>
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <core/keyboard.hpp>
#include <core/mouse.hpp>
#include <core/triangle.hpp>
#include <spdlog/spdlog.h>
#include <string>

class Application
{
public:
    static Application *Create(const char *windowTitle, const int &windowWidth, const int &windowHeight);
    static Application *GetCurrentApplication() { return currentApplication; };
    static void Terminate();

private:
    static Application *currentApplication;
    Application(const char *windowTitle, const int &windowWidth, const int &windowHeight);
    ~Application();

public:
    void Run();
    GLFWwindow *getCurrentContext();
    int getBufferWidht() const;
    int getBufferHeight() const;
    void SetFrameRate(unsigned int fps);
    void Toggle_ShowFPSInTitle();

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

private:
    Triangle *triangle;

private:
    GLFWwindow *window;
    std::string windowTitle;
    int windowWidth, windowHeight;
    int bufferWidth, bufferHeight;

private:
    bool showFpsInWindowTitle;
    unsigned int targetfps, fps;
    double fpsToleranceLimitMultiplyer;
    std::chrono::high_resolution_clock::time_point previousTime, currentTime;
    long double targetFrameTime, deltaTime;
};

#endif // __APPLICATION_H__