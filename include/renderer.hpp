#include <vector>

#pragma once
class Renderer {
public:
    Renderer();
    ~Renderer();
    void renderBlock(GLint x, GLint y, GLint z);
private:
    GLuint _vao;
    GLuint _vbo;
    std::vector<GLfloat> _vertices;
    void assembleBlock(GLfloat x, GLfloat y, GLfloat z);
    void addVertex(std::vector<GLfloat> vertex);
};
