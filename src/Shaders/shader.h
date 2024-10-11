#pragma once
#include "../config.h"
#include <fstream>
#include <sstream>

class Shader {
    public:
    Shader(const std::string& v_path, const std::string& f_path);
    void use();
    ~Shader();
    unsigned int getShaderLoc();

    private:
    unsigned int shader_program;
    unsigned int make_module(const std::string& path, unsigned int shader_type);
};