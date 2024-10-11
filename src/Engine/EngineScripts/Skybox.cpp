#include "Skybox.h"

Skybox::Skybox(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void Skybox::update() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

Skybox::~Skybox() {
    
}