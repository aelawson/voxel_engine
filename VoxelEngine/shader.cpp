//
//  shader.cpp
//  VoxelEngine
//
//  Created by Andrew Lawson on 8/2/15.
//
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>

#include "include/shader.hpp"

using namespace std;

string loadShaderFile(string filePath) {

    string content;
    ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        cout << "Could not read file " << filePath << ". File does not exist." << endl;
        return "";
    }

    string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

GLuint loadShaders(string vertexFilePath, string fragmentFilePath) {

    // Create the shaders
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Read the Vertex Shader code from the file
    std::string vertexShaderCode;
    vertexShaderCode = loadShaderFile(vertexFilePath);
    std::string fragmentShaderCode;
    fragmentShaderCode = loadShaderFile(fragmentFilePath);

    GLint result;

    // Compile Vertex Shader
    cout << "Compiling vertex shader." << endl;
    char const *vertexSourcePointer = vertexShaderCode.c_str();
    glShaderSource(vertexShaderID, 1, &vertexSourcePointer, NULL);
    glCompileShader(vertexShaderID);
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);

    if (result) {
        cout << "Vertex shader compiled successfully." << endl;
    }
    else {
        cout << "Vertex shader failed to compile. Exiting." << endl;
        exit(EXIT_FAILURE);
    }

    // Compile Fragment Shader
    cout << "Compiling fragment shader." << endl;
    char const *fragmentSourcePointer = fragmentShaderCode.c_str();
    glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer, NULL);
    glCompileShader(fragmentShaderID);
    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);

    if (result) {
        cout << "Fragment shader compiled successfully." << endl;
    }
    else {
        cout << "Fragment shader failed to compile. Exiting." << endl;
        exit(EXIT_FAILURE);
    }

    // Link the program
    cout << "Linking program." << endl;
    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glBindFragDataLocation(programID, 0, "outColor");
    glLinkProgram(programID);

    return programID;
}
