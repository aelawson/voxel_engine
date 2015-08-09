//
//  main.cpp
//  VoxelEngine
//
//  Created by Andrew Lawson on 8/1/15.
//  Copyright (c) 2015 Andrew Lawson. All rights reserved.
//

// General
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// OpenGL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <include/renderer.hpp>
#include <include/chunk.hpp>
#include <include/shader.hpp>

using namespace glm;

int main() {

    // Initialize GLFW
    int result = glfwInit();

    if (!result) {
        fprintf(stderr, "Failed to initialize GLFW.\n");
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(1024, 768, "VoxelEngine", NULL, NULL);

    if (window == NULL) {
        fprintf(stderr, "Failed to open GLFW window.\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    result = glewInit();
    if (result != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW.\n");
        return -1;
    }

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint posBuffer;
    glGenBuffers(1, &posBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, posBuffer);

    GLfloat vertices[] = {
        0.0f, 0.5f,
        0.5f, -0.5f,
        -0.5f, -0.5f
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    Renderer renderer;
    Chunk chunk(renderer);

    GLuint programID = loadShaders("/Users/andrewlawson/Documents/VoxelEngine/VoxelEngine/SimpleVertexShader.vertexshader",
        "/Users/andrewlawson/Documents/VoxelEngine/VoxelEngine/SimpleFragmentShader.fragmentshader");
    glUseProgram(programID);
    GLint posAttrib = glGetAttribLocation(programID, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //chunk.renderChunk();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup VBO
    glDeleteProgram(programID);
    glDeleteBuffers(1, &posBuffer);
    glDeleteVertexArrays(1, &vao);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
