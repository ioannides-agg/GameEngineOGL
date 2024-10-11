#include "shader.h"

//Constructor creates the shader_program.
Shader::Shader(const std::string& v_path, const std::string& f_path) {

    //create a vector of locations pointing to the modules vertex 
    //and fragment created by the make_module() function
    std::vector<unsigned int> modules = {
        make_module(v_path, GL_VERTEX_SHADER),
        make_module(f_path, GL_FRAGMENT_SHADER)
    };

    //create the shader program and assign it to the private var shader_program
    shader_program = glCreateProgram();

    //attach shader modules to the program.
    glAttachShader(shader_program, modules[0]);
    glAttachShader(shader_program, modules[1]);

    //link the program
    glLinkProgram(shader_program);

    //call glGetProgramiv to return the status to the int reference success 
    //and check if it was linked succesfully
    int success;
    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if(!success) {
        //if not return the error_log retrievied from glGetProgramInfoLog
        char error_log[512];
        glGetProgramInfoLog(shader_program, 512, NULL, error_log);
        std::cout << "Error compiling shader PROGRAM: \n" << error_log;
    }

    //Delete the shader modules since we linked them.
    glDeleteShader(modules[0]);
    glDeleteShader(modules[1]);
}

Shader::~Shader() {
    //Delete the shader program when the Destructor is called.
    glDeleteProgram(shader_program);
}

//function that creates the modules required for the final shader program:
//vertex module = Tells the GPU where/how to draw the vertices
//fragment module = Tells the GPU how to color the fragments of pixels
unsigned int Shader::make_module(const std::string& path, unsigned int shader_type) {

    //instantiate necessary values for file creation
    std::ifstream file;
    std::stringstream str_buffer;
    std::string line;

    //open the path of the module
    file.open(path);
    while (std::getline(file, line)) {
        //std::cout << line << "\n";
        //pass the file in a string buffer
        str_buffer << line << "\n";
    }

    //convert the buffer to a string, then the string to a c_string
    //note: this process cannot be done in one line as the str() 
    //converter gets the pointer in the string data, which gets the 
    //string out of scope for c_str() call.
    std::string shader_source = str_buffer.str();
    const char* shader_src = shader_source.c_str();

    //clears the buffer, closes the file to release memory.
    str_buffer.str("");
    file.close();

    //creates the specific shader based on the type
    unsigned int _shader;
    _shader = glCreateShader(shader_type);

    //connects the shader to the source code of it and compiles it
    glShaderSource(_shader, 1, &shader_src, NULL);
    glCompileShader(_shader);

    //Check if the compilation of the shader source code is done succesfully
    int success;
    glGetShaderiv(_shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        char error_log[512];
        glGetShaderInfoLog(_shader, 512, NULL, error_log);
        std::cout << "Error compiling shader " << path << ": \n"
        << error_log;
    }

    //returns the shader module
    return _shader;
}

unsigned int Shader::getShaderLoc() {
    //return the address of the shader_program
    return shader_program;
}