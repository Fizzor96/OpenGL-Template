#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#ifdef MSVC
#include <Windows.h>
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <core/keyboard.hpp>
#include <core/mouse.hpp>
#include <core/triangle.hpp>
#include <iostream>
#include <spdlog/spdlog.h>
#include <string>

class Application
{
public:
    Application(const char *windowTitle, const int &windowWidth, const int &windowHeight);
    ~Application();

public:
    void run();
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
    void setViewport();
    void cleanup();

private:
    GLFWwindow *window;
    std::string windowTitle;
    int windowWidth, windowHeight;
    int bufferWidth, bufferHeight;
    Triangle *triangle;
};

#endif // __APPLICATION_H__