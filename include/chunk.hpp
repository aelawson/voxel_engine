// OpenGL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "include/renderer.hpp"
#include "include/block.hpp"

#pragma once
class Chunk {
public:
    static const int CHUNK_SIZE = 16;
    Chunk(Renderer renderer);
    ~Chunk();
    void update(float dt);
    void renderChunk();
    Renderer getRenderer();
private:
    Renderer _renderer;
    Block ***_blocks;
};
