#include <iostream>
#include <vector>

// OpenGL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "include/chunk.hpp"

using namespace std;

/*
    Constructors
*/

Chunk::Chunk(Renderer renderer) {
    _renderer = renderer;
    _blocks = new Block**[Chunk::CHUNK_SIZE];
    for (int i = 0; i < Chunk::CHUNK_SIZE; i++) {
        for (int j = 0; j < Chunk::CHUNK_SIZE; j++) {
            _blocks[i][j] = new Block[Chunk::CHUNK_SIZE];
        }
    }
    cout << "Created chunk!" << endl;
}

Chunk::~Chunk() {
    for (int i = 0; i < Chunk::CHUNK_SIZE; i++) {
        for (int j = 0; j < Chunk::CHUNK_SIZE; j++) {
            delete [] _blocks[i][j];
        }
        delete [] _blocks[i];
    }
    delete [] _blocks;
    cout << "Destructed chunk!" << endl;
}

/*
    Methods
*/

void Chunk::update(float dt) {
    // Nothing new.
}

void Chunk::renderChunk() {
    for (GLfloat x = 0.0f; x < Chunk::CHUNK_SIZE; x++) {
        for (GLfloat y = 0.0f; y < Chunk::CHUNK_SIZE; y++) {
            for (GLfloat z = 0.0f; z < Chunk::CHUNK_SIZE; z++) {
                _renderer.renderBlock(x * Chunk::CHUNK_SIZE, y * Chunk::CHUNK_SIZE, z * Chunk::CHUNK_SIZE);
            }
        }
    }
}

Renderer Chunk::getRenderer() {
    return _renderer;
}
