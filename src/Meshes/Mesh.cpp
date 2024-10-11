#include "Mesh.h"

Mesh::Mesh() {
    /*setVertices();
    bufferMesh();*/
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Mesh::setVertices() {
    std::cout << "Empty Mesh Object" << std::endl;
}


void Mesh::bufferMesh() {
    std::cout << "Empty Mesh Object" << std::endl;
}

void Mesh::draw() {
}

/*void Mesh::setPos(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
}*/

/*void Mesh::setShader(unsigned int shader) {
    internal_shader = shader;
}*/