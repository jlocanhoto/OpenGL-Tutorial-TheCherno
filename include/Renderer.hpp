#pragma once

#include <GL/glew.h>

#include <csignal>

#define ASSERT(x) if (!(x)) raise(SIGABRT)

#ifdef DEBUG
    #define GLCall(x) GLClearError();\
        x;\
        ASSERT(GLLogCall(#x, __FILE__, __LINE__))

    void GLClearError();
    bool GLLogCall(const char* function, const char* file, int line);
#else
    #define GLCall(x) x
#endif