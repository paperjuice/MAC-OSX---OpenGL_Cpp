//
//  array_draw.cpp
//  OpenGl
//
//  Created by Dragos Dumitru on 2017-08-23.
//  Copyright © 2017 Dragos Dumitru. All rights reserved.
//

#include "array_draw.hpp"
#include <iostream>



Array_Draw::Array_Draw(){}
Array_Draw::~Array_Draw(){
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    glDeleteBuffers(1, &VAO);
    glDeleteBuffers(1, &VBO);
    
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


SDL_Window* Array_Draw::Init_SDL(const GLchar* title, const GLint &x_pos, const GLint &y_pos, const GLuint &width, const GLuint &height, const GLint &flag)
{
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 7);
    
    window = SDL_CreateWindow(title, x_pos, y_pos, width, height, SDL_WINDOW_OPENGL);
    
    context = SDL_GL_CreateContext(window);
    
    glewExperimental = true;
    glewInit();
    
    glViewport(0, 0, width, height);
    
    return window;
}

GLint Array_Draw::Create_vertex_shader()
{
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    
    if(!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, log_info);
        std::cout << "Vertex shader failed: " << log_info << std::endl;
        return 0;
    }
    else
    {
        return vertex_shader;
    }
}


GLint Array_Draw::Create_fragment_shader(){
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    
    if(!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, log_info);
        std::cout<<"Fragment shader failed to compile: " << log_info << std::endl;
        return 0;
    }
    else
    {
        return fragment_shader;
    }
}

GLint Array_Draw::Create_program_shader_obj(GLint vs, GLint fs)
{
    GLint program_shader = glCreateProgram();
    glAttachShader(program_shader, vs);
    glAttachShader(program_shader, fs);
    glLinkProgram(program_shader);
    
    glGetProgramiv(program_shader, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(program_shader, 512, NULL, log_info);
        std::cout<<"Linking error: " << log_info << std::endl;
        return 0;
    }
    else {
        return program_shader;
    }
}

GLuint Array_Draw::Create_buffers()
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 *sizeof(GLfloat), (GLvoid*)0);
    
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    return VAO;
}

























