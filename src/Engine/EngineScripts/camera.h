#pragma once
#include "../EngineObject.h"

class Camera : public EngineBehaviour {
    public:
    const glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    const glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
    const glm::vec3 right = glm::normalize(glm::cross(front, up));
    Camera(unsigned int shader, glm::vec3 initial_pos, glm::vec3 initial_look_pos, float FOV);
    ~Camera();
    void update();
    void LookAt(unsigned int shader, glm::vec3 target);
    void Move(unsigned int shader, glm::vec3 newPos);
    glm::vec3 getPosition();
    float getSpeed();

    private:
    unsigned int viewPtr, projectionPtr;
    glm::vec3 calculateDirection();
    glm::vec3 cameraPos, cameraTarget, cameraDirection;
    glm::mat4 view, proj;
    const float speed = 4.0f;
};