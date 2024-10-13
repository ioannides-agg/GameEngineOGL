cmake_minimum_required(VERSION 3.30.4)
project(aggelEngine VERSION 0.1.0)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.4 REQUIRED)

add_library(aggelEngineLibs STATIC
    src/includes/glad/glad.c
    src/includes/stb_image/stb_image.cpp
    src/Shaders/shader.cpp
    src/Engine/EngineCore.cpp
    src/Engine/Renderer.cpp
    src/Engine/EngineScripts/Skybox.cpp
    src/Engine/EngineScripts/camera.cpp
    src/Meshes/Mesh.cpp
    src/Meshes/meshTypes/Box.cpp
    src/Meshes/materials/material.cpp
    src/Components/Object.cpp
)

add_library(Scripts STATIC 
    src/Engine/Scripts/TestScript.cpp
)

add_executable(aggelEngine
    src/main.cpp
)

target_include_directories(aggelEngine PRIVATE dependencies)
target_include_directories(aggelEngineLibs PRIVATE dependencies)
target_include_directories(Scripts PRIVATE dependencies)

target_link_libraries(aggelEngine
    aggelEngineLibs
    glfw OpenGL::GL
    Scripts
    )