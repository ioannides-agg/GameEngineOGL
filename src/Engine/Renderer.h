#pragma once
#include "../Components/Object.h"

class Renderer {
    public:
    Renderer();
    void update();
    void add(Object* obj);
    ~Renderer();

    private:
    std::vector<Object*> objs;
};