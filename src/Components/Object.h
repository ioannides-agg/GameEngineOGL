#pragma once
#include "../Meshes/meshConfig.h"
#include "../Engine/EngineObject.h"
#include "Transform.h"

class Object {
    public:
    Transform transform;
    Object(Mesh* _model, material* _mat, unsigned int internal_shader);
    void render();
    void attachScript(EngineBehaviour* s);
    std::vector<EngineBehaviour*> getAttachedScripts();

    private:
    std::vector<EngineBehaviour*> scripts;
    glm::mat4 local;
    unsigned int internal_shader;
    Mesh* model;
    material* mat;
};