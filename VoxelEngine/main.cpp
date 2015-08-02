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

using namespace glm;

GLFWwindow* window;

int main() {
    
    // Initialize GLFW
    int result = glfwInit();
    
    if (!result) {
        fprintf(stderr, "Failed to initialize GLFW.\n");
        return -1;
    }
    
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    
    window = glfwCreateWindow(1024, 768, "VoxelEngine", NULL, NULL);
    
    if (window == NULL) {
        fprintf(stderr, "Failed to open GLFW window.\n");
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    
    // Initialize GLEW
    result = glewInit();
    
    if (result != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW.\n");
        return -1;
    }
    
    // Set sceen to dark blue
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    
    // Event loop
    do {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0);
    
    glfwTerminate();
    
    return 0;
}