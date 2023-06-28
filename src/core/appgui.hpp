#ifndef __APPGUI_H__
#define __APPGUI_H__

#include <core/application.hpp>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <spdlog/spdlog.h>
#include <string>

class Application;

class AppGui
{
public:
    AppGui(GLFWwindow *window);
    ~AppGui();

    void NewFrame();
    void Setup();
    void Render();
    void ProcessEvent(const GLFWwindow *window, const int key, const int scancode, const int action, const int mods);

private:
    void SetupImGuiStyle();
    std::string mystr;
    Application *app;
};

#endif // __APPGUI_H__