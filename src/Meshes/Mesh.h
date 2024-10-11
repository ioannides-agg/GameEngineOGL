#pragma once
#include "../config.h"

class Mesh {
    public:
    Mesh();
    //void setPos(float _x, float _y, float _z);
    virtual void draw();
    //void setShader(unsigned int shader);
    ~Mesh();

    protected:
    //float x, y, z = 0.0f;
    virtual void setVertices();
    virtual void bufferMesh();
    //unsigned int internal_shader;
    std::vector<float> vertices;
    std::vector<int> elements;
    unsigned int VAO, VBO;
    int Elements;
};