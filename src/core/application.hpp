#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <spdlog/spdlog.h>
#include <string>

class Application
{
public:
    Application(const char *windowTitle, const int &windowWidth, const int &windowHeight);
    ~Application();

    void run();
    GLFWwindow *getCurrentContext();
    int getBufferWidht() const;
    int getBufferHeight() const;

private:
    void initialize();
    void createWindow();
    void setupContext();
    void initializeGLEW();
    void initializeGLFW();
    void setViewport();
    void handleInput();
    void renderFrame();
    void cleanup();

    GLFWwindow *window;
    std::string windowTitle;
    int windowWidth, windowHeight;
    int bufferWidth, bufferHeight;
};

#endif // __APPLICATION_H__