#include "Renderer.h"

Renderer::Renderer() {
    //instance = this;
}

Renderer::~Renderer() {
    /*for(Mesh* mesh : meshes) {
        delete mesh;
    }*/

   //delete instance;
}

void Renderer::add(Object* obj) {
    objs.push_back(obj);
}

void Renderer::update() {
    if(objs.size() <= 0) {
        return;
    }

    for(int i = 0; i <= objs.size() - 1; i++) {
        objs[i] -> render();
    }
}