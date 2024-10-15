#pragma once
#include "../config.h"

class EngineBehaviour {
    public:
    std::uintptr_t object_addr;
    EngineBehaviour() {}
    virtual void update() {}
    ~EngineBehaviour() {}
};