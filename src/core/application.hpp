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
#include <iostream>
#include <spdlog/spdlog.h>
#include <string>
#include <thread>

class Application
{
public:
    static Application *Create(const char *windowTitle, const int &windowWidth, const int &windowHeight);
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
    void initspdlogpattern();
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
    unsigned int targetfps, fps;
    std::chrono::high_resolution_clock::time_point previousTime, currentTime;
    long double targetFrameTime, deltaTime;
};

#endif // __APPLICATION_H__