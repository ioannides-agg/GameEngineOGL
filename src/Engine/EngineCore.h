#pragma once
#include "../config.h"
#include "EngineObject.h"

namespace core {

class EngineCore {
    public:
    EngineCore();
    ~EngineCore();
    void callUpdateFunctions();
    void linkUpdate(std::shared_ptr<EngineBehaviour> obj);
    int getCoreStatus();
    GLFWwindow* mainWindow;
    void setShader(unsigned int);
    unsigned int getShader();

    private:
    unsigned int _shader;
    int coreStatus;
    int initializeCore();
    void coreUpdate();
    std::vector<std::shared_ptr<EngineBehaviour>> modules;
};

void onWindowResizeCallback(GLFWwindow* win, int width, int height);
}