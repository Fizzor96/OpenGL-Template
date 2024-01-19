#ifndef __ImGui_H__
#define __ImGui_H__

#include <core/App.hpp>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui_internal.h>
#include <spdlog/spdlog.h>
#include <string>

class App;

class Gui
{
public:
    Gui(App *app);
    ~Gui();

    void NewFrame();
    void Setup();
    void Render();
    void ProcessEvent(const GLFWwindow *window, const int key, const int scancode, const int action, const int mods);

private:
    void SetupImGuiStyle();
    std::string mystr;
};

#endif // __ImGui_H__