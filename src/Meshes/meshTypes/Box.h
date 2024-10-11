#include "../Mesh.h"

class Box : public Mesh
{
    public:
    Box();
    void draw();
    private:
    void setVertices();
    void bufferMesh();
};