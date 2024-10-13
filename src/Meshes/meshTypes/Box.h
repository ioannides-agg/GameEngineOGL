#include "../Mesh.h"
#include "../../config.h"

class Box : public Mesh
{
    public:
    Box();
    void draw();
    private:
    void setVertices();
    void bufferMesh();
};