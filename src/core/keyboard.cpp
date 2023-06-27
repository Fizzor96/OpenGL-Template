#include <core/keyboard.hpp>

void Keyboard::traceKeys(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        // Get the corresponding letter from the key code
        std::string letter;
        if (key >= GLFW_KEY_A && key <= GLFW_KEY_Z)
            letter = static_cast<char>('A' + (key - GLFW_KEY_A));
        else
            letter = "Unknown";

        spdlog::warn(
            "Key pressed: Letter = {0}, Keycode = {1},  Scancode = {2}", letter, key, scancode);
    }

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
    {
        Application::GetCurrentApplication()->SetFrameRate(60);
    }

    if (key == GLFW_KEY_F2 && action == GLFW_PRESS)
    {
        Application::GetCurrentApplication()->SetFrameRate(90);
    }

    if (key == GLFW_KEY_F3 && action == GLFW_PRESS)
    {
        Application::GetCurrentApplication()->SetFrameRate(144);
    }

    if (key == GLFW_KEY_F4 && action == GLFW_PRESS)
    {
        Application::GetCurrentApplication()->SetFrameRate(300);
    }

    if (key == GLFW_KEY_F5 && action == GLFW_PRESS)
    {
        Application::GetCurrentApplication()->Toggle_ShowFPSInTitle();
    }
}