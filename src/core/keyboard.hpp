#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <GLFW/glfw3.h>
#include <iostream>
#include <spdlog/spdlog.h>

class Keyboard
{
public:
    static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
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
    }
};

#endif // __KEYBOARD_H__