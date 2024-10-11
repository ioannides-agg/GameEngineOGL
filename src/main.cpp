#include "config.h"
#include "Engine/EngineCore.h"
#include "Shaders/shader.h"
#include "Engine/Renderer.h"
#include "Engine/InputManager.h"
#include "Engine/Scripts/Scripts.h"

//load the Engine Core and additional core functionalities of engine
EngineCore Engine;

void ProcessInput();

int main() {

    if(!Engine.getCoreStatus()) {
        std::cout << "Core Failed to initialize" << std::endl;
        return -1;
    }

    Shader shader{"../src/Shaders/shaders/vertex.txt", "../src/Shaders/shaders/fragment.txt"};

    //Initialize renderer
    Renderer renderer;

    //link the update functions of the Engine Scripts
    Skybox sb{0.2f, 0.4f, 0.8f, 1.0f};
    Camera camera{shader.getShaderLoc(), glm::vec3(0.0f, 0.0f, -3.0f), glm::vec3(0.0f, 0.0f, 0.0f), 90.0f};

    Engine.linkUpdate(&sb);
    Engine.linkUpdate(&camera);

    //configure the materials
    material mat{"../Assets/images/funimage1.jpg"};
    glUniform1i(glGetUniformLocation(shader.getShaderLoc(), "tex"), 0);
    glUniform1i(glGetUniformLocation(shader.getShaderLoc(), "tex2"), 1);

    //configure Meshes
    Box box;
    //box.setPos(0.0f, 0.0f, 0.0f);
    //box.setShader(shader.getShaderLoc());

    Object boxObj{&box, &mat, shader.getShaderLoc()};
    boxObj.attachScript(new TestScript());

    for(EngineBehaviour* script : boxObj.getAttachedScripts()) {
        Engine.linkUpdate(script);
    }

    renderer.add(&boxObj);

    //call the update loop
    while (!glfwWindowShouldClose(Engine.mainWindow)) {
        ProcessInput();

        Engine.callUpdateFunctions();
        renderer.update();

        glfwSwapBuffers(Engine.mainWindow);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void ProcessInput() {
    if(InputManager::GetKeyPress(Keys::ESC)) {
        glfwSetWindowShouldClose(Engine.mainWindow, true);
    }
}