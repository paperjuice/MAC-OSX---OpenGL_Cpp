//
//  array_draw.hpp
//  OpenGl
//
//  Created by Dragos Dumitru on 2017-08-23.
//  Copyright © 2017 Dragos Dumitru. All rights

#ifndef array_draw_hpp
#define array_draw_hpp

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


class Array_Draw{
public:
    Array_Draw();
    ~Array_Draw();
    SDL_Window* Init_SDL(const GLchar* title, const GLint &x_pos, const GLint &y_pos, const GLuint &width, const GLuint &height, const GLint &flag);
    GLint Create_vertex_shader();
    GLint Create_fragment_shader();
    GLint Create_program_shader_obj(GLint vertex_shader, GLint fragment_shader);
    GLuint Create_buffers();
    
    
    
private:
    SDL_Window* window = nullptr;
    GLboolean is_running = GL_TRUE;
    GLint success = 0;
    GLchar log_info[512];
    const char* TITLE = "ArrayDraw";
    SDL_GLContext context;
    
    GLuint vertex_shader;
    const GLchar* vertex_shader_source=
    "#version 330 core\n"
    "layout(location=0) in vec3 pos;"
    "void main(void){\n"
    "gl_Position = vec4(pos.x, pos.y, pos.z, 1.0f);\n"
    "}\0s";
    
    GLint fragment_shader;
    const GLchar* fragment_shader_source =
    "#version 330 core\n"
    "out vec4 color;\n"
    "float r = 186.0/255.0, g = 45.0/255.0, b = 35.0/255.0;\n"
    "void main(void){\n"
    "color = vec4(r, g, b, 1.0f);\n"
    "}\0";
    
    const GLfloat vertices[54] = {
        -.1, 0.4f, 0.f,
        0.f,  .3f, 0.f,
        0.f, 0.f, 0.f,
        
        0.f, 0.f, 0.f,
        -.1f, .4f, 0.f,
        -.2f, .4f, 0.f,
        
        -.2f, .4f, 0.f,
        0.f, 0.f, 0.f,
        -.25f, 0.25f, 0.f,
        
        .1f, 0.4f, 0.f,
        0.f,  .3f, 0.f,
        0.f, 0.f, 0.f,
        
        0.f, 0.f, 0.f,
        .1f, .4f, 0.f,
        .2f, .4f, 0.f,
        
        .2f, .4f, 0.f,
        0.f, 0.f, 0.f,
        .25f, 0.25f, 0.f
    };
    
    
    GLuint VAO, VBO;
    
};








#endif


