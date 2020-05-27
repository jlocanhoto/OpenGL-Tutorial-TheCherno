#include "../include/Renderer.hpp"

#include <iostream>

#ifdef DEBUG
    void GLClearError() {
        while (glGetError() != GL_NO_ERROR);
    }

    bool GLLogCall(const char* function, const char* file, int line) {
        bool result = true;

        while (GLenum error = glGetError()) {
            std::cout << "[OpenGL Error] 0x" << std::hex << error << std::dec << ":" << std::endl <<
                        "FUNCTION CALL: " << function << std::endl <<
                        "FILE: " << file << ":" << line << std::endl << std::endl;
            result &= false;
        }

        return result;
    }
#else
    #define GLCall(x) x
#endif