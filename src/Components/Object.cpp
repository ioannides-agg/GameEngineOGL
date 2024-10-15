#include "Object.h"

Object::Object(std::shared_ptr<Mesh> _model, std::shared_ptr<material> _mat, unsigned int shader) {
    model = _model;
    mat = _mat;
    internal_shader = shader;
    transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Object::render() {
    glUseProgram(internal_shader);

    //std::cout << "aaa - " << transform.rotation.y << std::endl;
    local = glm::mat4(1.0f);
    local = glm::translate(local, transform.position);
    local = glm::rotate(local, glm::radians(transform.rotation.y), glm::vec3(1.0f, 0.0f, 0.0f));
    local = glm::rotate(local, glm::radians(transform.rotation.x), glm::vec3(0.0f, 1.0f, 0.0f));
    local = glm::rotate(local, glm::radians(transform.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    glUniformMatrix4fv(glGetUniformLocation(internal_shader, "model"), 1, GL_FALSE, glm::value_ptr(local));

    mat->use(0);
    model->draw();
}

void Object::attachScript(std::shared_ptr<EngineBehaviour> s) {
    scripts.push_back(s);
    s->object_addr = (std::uintptr_t)this;
}

std::vector<std::shared_ptr<EngineBehaviour>> Object::getAttachedScripts() {
    return scripts;
}