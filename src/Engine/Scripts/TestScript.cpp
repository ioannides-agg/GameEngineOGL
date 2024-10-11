#include "../EngineObject.h"
#include "../../EngineLibrary.h"

class TestScript : public EngineBehaviour {

    public:

    TestScript() {

    }

    void update() {
        ((Object*)object_addr) -> transform.rotation = glm::vec3(0.0f, 45.0f * (float)glfwGetTime(), 0.0f);
    }

};

