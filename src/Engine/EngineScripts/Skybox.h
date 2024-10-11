#include "../EngineObject.h"

class Skybox : public EngineBehaviour {
    public:
    Skybox(float r, float g, float b, float a);
    void update();
    ~Skybox();
};