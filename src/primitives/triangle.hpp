#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Triangle
{
public:
    Triangle();
    ~Triangle();

    void render();

private:
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;
    GLuint VBO;
    GLuint VAO;
};

#endif // __TRIANGLE_H__