#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <core/application.hpp>
#include <iostream>
#include <spdlog/spdlog.h>

class Keyboard
{
public:
    static void traceKeys(GLFWwindow *window, int key, int scancode, int action, int mods);
};

#endif // __KEYBOARD_H__