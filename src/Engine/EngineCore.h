#pragma once
#include "EngineScripts/EngineScriptsConfig.h"

class EngineCore {
    public:
    EngineCore();
    ~EngineCore();
    void callUpdateFunctions();
    void linkUpdate(EngineBehaviour* obj);
    int getCoreStatus();
    GLFWwindow* mainWindow;
    void setShader(unsigned int);
    unsigned int getShader();

    private:
    unsigned int _shader;
    int coreStatus;
    int initializeCore();
    void coreUpdate();
    std::vector<EngineBehaviour*> modules;
};

void onWindowResizeCallback(GLFWwindow* win, int width, int height);