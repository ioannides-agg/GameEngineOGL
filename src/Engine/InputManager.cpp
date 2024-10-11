#include "InputManager.h"

bool InputManager::GetKeyPress(int key) {
        return glfwGetKey(glfwGetCurrentContext(), key) == GLFW_PRESS;
}