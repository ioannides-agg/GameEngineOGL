#pragma once
#include "../../config.h"

class material {
    public:
    material(const char* path);
    void use(int unit);
    ~material();

    private:
    unsigned int texture;
};