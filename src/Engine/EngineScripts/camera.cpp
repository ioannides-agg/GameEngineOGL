#include "camera.h"

Camera::Camera(unsigned int shader, glm::vec3 initial_pos, glm::vec3 initial_look_pos, float FOV) {
    proj = glm::perspective(glm::radians(FOV), 800.0f/600.0f, 0.1f, 100.0f);
    projectionPtr = glGetUniformLocation(shader, "projection");

    cameraPos = initial_pos;
    cameraTarget = initial_look_pos;
    cameraDirection = glm::normalize(cameraPos - cameraTarget);

    this->LookAt(shader, cameraTarget);
}

Camera::~Camera() {

}

void Camera::update() {
    glUniformMatrix4fv(viewPtr, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionPtr, 1, GL_FALSE, glm::value_ptr(proj));
}

void Camera::LookAt(unsigned int shader, glm::vec3 target) {
    cameraTarget = target;
    cameraDirection = calculateDirection();
    view = glm::lookAt(cameraPos, cameraTarget, up);
    viewPtr = glGetUniformLocation(shader, "view");
    //glUniformMatrix4fv(glGetUniformLocation(shader, "view"), 1, GL_FALSE, glm::value_ptr(view));
}

void Camera::Move(unsigned int shader, glm::vec3 newPos) {
    cameraPos = newPos;
    cameraDirection = calculateDirection();
    view = glm::lookAt(cameraPos, cameraPos + front, up);
    viewPtr = glGetUniformLocation(shader, "view");
    //glUniformMatrix4fv(glGetUniformLocation(shader, "view"), 1, GL_FALSE, glm::value_ptr(view));
}

glm::vec3 Camera::calculateDirection() {
    return glm::normalize(cameraPos - cameraTarget);
}

glm::vec3 Camera::getPosition() {
    return cameraPos;
}

float Camera::getSpeed() {
    return speed;
}

