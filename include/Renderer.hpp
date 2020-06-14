#pragma once

#include <GL/glew.h>

#include "external/debugbreak.h"

#define ASSERT(x) if (!(x)) debug_break()

#ifdef DEBUG
    #define GLCall(x) GLClearError();\
        x;\
        ASSERT(GLLogCall(#x, __FILE__, __LINE__))

    void GLClearError();
    bool GLLogCall(const char* function, const char* file, int line);
#else
    #define GLCall(x) x
#endif