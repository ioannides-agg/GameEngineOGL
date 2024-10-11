#pragma once
#include "../config.h"
#include <map>

class EngineBehaviour {
    public:
    std::uintptr_t object_addr;
    EngineBehaviour();
    virtual void update();
    ~EngineBehaviour();
};