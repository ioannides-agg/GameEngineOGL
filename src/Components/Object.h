#pragma once
#include "../config.h"
#include "../Meshes/meshConfig.h"
#include "../Engine/EngineObject.h"
#include "Transform.h"

class Object {
    public:
    Transform transform;
    Object(std::shared_ptr<Mesh> _model, std::shared_ptr<material> _mat, unsigned int internal_shader);
    void render();
    void attachScript(std::shared_ptr<EngineBehaviour> s);
    std::vector<std::shared_ptr<EngineBehaviour>> getAttachedScripts();

    private:
    std::vector<std::shared_ptr<EngineBehaviour>> scripts;
    glm::mat4 local;
    unsigned int internal_shader;
    std::shared_ptr<Mesh> model;
    std::shared_ptr<material> mat;
};