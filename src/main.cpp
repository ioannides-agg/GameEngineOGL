#include "config.h"
#include "Shaders/shader.h"
#include "EngineLibrary.h"
#include "Engine/Scripts/Scripts.h"
#include "Engine/EngineScripts/EngineScriptsConfig.h"

//load the Engine Core and additional core functionalities of engine
core::EngineCore Engine;

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
    std::shared_ptr<Skybox> sb (new Skybox(0.2f, 0.4f, 0.8f, 1.0f));
    std::shared_ptr<Camera> camera (new Camera(shader.getShaderLoc(), 
                                    glm::vec3(0.0f, 0.0f, -3.0f), 
                                    glm::vec3(0.0f, 0.0f, 0.0f), 90.0f));

    Engine.linkUpdate(sb);
    Engine.linkUpdate(camera);

    //configure the materials
    std::shared_ptr<material> mat (new material("../Assets/images/container.jpg"));
    glUniform1i(glGetUniformLocation(shader.getShaderLoc(), "tex"), 0);
    glUniform1i(glGetUniformLocation(shader.getShaderLoc(), "tex2"), 1);

    //configure Meshes
    std::shared_ptr<Mesh> box (new Box);

    Object boxObj{box, mat, shader.getShaderLoc()};
    std::shared_ptr<TestScript> ts (new TestScript());
    boxObj.attachScript(ts);

    for(std::shared_ptr<EngineBehaviour> script : boxObj.getAttachedScripts()) {
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