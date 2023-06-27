#ifndef __APPGUI_H__
#define __APPGUI_H__

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

class ImGuiWrapper
{
public:
    ImGuiWrapper(GLFWwindow *window);
    ~ImGuiWrapper();

    void NewFrame();
    void Update();
    void Render();

private:
    ImGuiIO *io;
};

#endif // __APPGUI_H__