#pragma once
#include "../config.h"

//TODO: implement Input Manager
class InputManager {
    public:
    static bool GetKeyPress(int Key);
};

struct Keys {
    public:
    static const int W = GLFW_KEY_W;
    static const int A = GLFW_KEY_A;
    static const int S = GLFW_KEY_S;
    static const int D = GLFW_KEY_D;
    static const int ESC = GLFW_KEY_ESCAPE;
};