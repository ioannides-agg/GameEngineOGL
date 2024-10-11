#include "EngineCore.h"

//intiliazes the core in the constructor
EngineCore::EngineCore() {
    coreStatus = initializeCore();
    //core = this;
}

//destructor for the linked update function objects
EngineCore::~EngineCore() {
    /*for(EngineBehaviour* module : modules) {
        delete module;
    }*/

   //delete core;
}

//call of all the update functions
void EngineCore::callUpdateFunctions() {
    if(modules.size() <= 0) {
        return;
    }

    for(int i = 0; i <= modules.size() - 1; i++) {
        modules[i] -> update();
    }
}

//linking function to add additional objects update 
//functions in the main loop for ease of additional components
void EngineCore::linkUpdate(EngineBehaviour* obj) {
    modules.push_back(obj);
}

//the update funtion of the core
void EngineCore::coreUpdate() {
    
}

//initializes the core, stores the status of success in coreStatus
int EngineCore::initializeCore() {
    std::cout << "Initializing Engine Core...\n";
    //Initialize glfw and ensure it is initialized correctly, otherwise throw error for debug
    if(!glfwInit()) {
        std::cout << "GLFW did not Initialize" << std::endl;
        return 0;
    }
    
    //glfw flags
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //starting window size
    int w = 800;
    int h = 600;

    //Create glfw window, make it the current window
    GLFWwindow* window = glfwCreateWindow(w, h, "AggelEngine", NULL, NULL);
    if(window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return 0;
    }

    glfwMakeContextCurrent(window);

    //load glad boilerplate
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Glad failed to load" << std::endl;
        glfwTerminate();
        return 0;
    }

    //configure the viewport
    //glViewport(0, 0, w, h);
    //Attach resize callback function and retrieve the new height, width
    glfwSetFramebufferSizeCallback(window, onWindowResizeCallback);

    std::cout << "Success! Engine core has been initialized succesfully!\n";

    glEnable(GL_DEPTH_TEST);
    mainWindow = window;
    return 1;
}

//returns core status
int EngineCore::getCoreStatus() {
    return coreStatus;
}

void EngineCore::setShader(unsigned int s) {
    _shader = s;
}

unsigned int EngineCore::getShader() {
    return _shader;
}

//CALLBACK FUNCTIONS UNRELATED TO CLASS
void onWindowResizeCallback(GLFWwindow* win, int width, int height) {
    glViewport(0, 0, width, height);
}