#include <vector>

// OpenGL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "include/block.hpp"
#include "include/renderer.hpp"

using namespace std;

/*
    Constructors
*/

Renderer::Renderer() {
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    cout << "Contructed renderer!" << endl;
}

Renderer::~Renderer() {
    cout << "Destructed renderer!" << endl;
}

/*
    Methods
*/

void Renderer::renderBlock(GLfloat x, GLfloat y, GLfloat z) {
    assembleBlock(x, y, z);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), &_vertices[0], GL_STATIC_DRAW);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::assembleBlock(GLfloat x, GLfloat y, GLfloat z) {
    vector<GLfloat> v1 = {x - Block::BLOCK_SIZE, y - Block::BLOCK_SIZE, z + Block::BLOCK_SIZE};
    vector<GLfloat> v2 = {x + Block::BLOCK_SIZE, y - Block::BLOCK_SIZE, z + Block::BLOCK_SIZE};
    vector<GLfloat> v3 = {x + Block::BLOCK_SIZE, y + Block::BLOCK_SIZE, z + Block::BLOCK_SIZE};
    vector<GLfloat> v4 = {x - Block::BLOCK_SIZE, y + Block::BLOCK_SIZE, z + Block::BLOCK_SIZE};
    vector<GLfloat> v5 = {x - Block::BLOCK_SIZE, y - Block::BLOCK_SIZE, z - Block::BLOCK_SIZE};
    vector<GLfloat> v6 = {x + Block::BLOCK_SIZE, y - Block::BLOCK_SIZE, z - Block::BLOCK_SIZE};
    vector<GLfloat> v7 = {x + Block::BLOCK_SIZE, y + Block::BLOCK_SIZE, z - Block::BLOCK_SIZE};
    vector<GLfloat> v8 = {x - Block::BLOCK_SIZE, y + Block::BLOCK_SIZE, z - Block::BLOCK_SIZE};
    addVertex(v1);
    addVertex(v2);
    addVertex(v3);
    addVertex(v4);
    addVertex(v5);
    addVertex(v6);
    addVertex(v7);
    addVertex(v8);
}

void Renderer::addVertex(vector<GLfloat> vertex) {
    _vertices.insert(vertex[0]);
    _vertices.insert(vertex[1]);
    _vertices.insert(vertex[2]);
}
