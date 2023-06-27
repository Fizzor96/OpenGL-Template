#ifndef __MOUSE_H__
#define __MOUSE_H__

#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

class Mouse
{
public:
    static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
    {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        {
            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);
            spdlog::warn(
                "Left mouse button clicked at ({0};{1})", xpos, ypos);
        }
        if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
        {
            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);
            spdlog::warn(
                "Right mouse button clicked at ({0};{1})", xpos, ypos);
        }
    }
};

#endif // __MOUSE_H__