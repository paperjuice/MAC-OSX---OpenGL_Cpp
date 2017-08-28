#include <iostream>
#include "array_draw.hpp"



int main(int argc, char* argv[])
{
    const GLchar* fragment_shader_source_up =
    "#version 330 core\n"
    "out vec4 color;\n"
    "float r = 186.0/255.0, g = 45.0/255.0, b = 35.0/255.0;\n"
    "void main(void){\n"
    "color = vec4(r, g, b, 1.0f);\n"
    "}\0";
    
    const GLchar* fragment_shader_source_down =
    "#version 330 core\n"
    "out vec4 color;\n"
    "float r = 246.0/255.0, g = 165.0/255.0, b = 165.0/255.0;\n"
    "void main(void){\n"
    "color = vec4(r, g, b, 1.0f);\n"
    "}\0";
    
    GLfloat vertices[] = {
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
    size_t vertices_size = sizeof(vertices);
    
    GLfloat vertices_2[] = {
        -.1, -0.4f, 0.f,
        0.f,  -.3f, 0.f,
        0.f, 0.f, 0.f,
        
        0.f, 0.f, 0.f,
        -.1f, -.4f, 0.f,
        -.2f, -.4f, 0.f,

        -.2f, -.4f, 0.f,
        0.f, 0.f, 0.f,
        -.25f, -0.25f, 0.f,
        
        .1f, -0.4f, 0.f,
        0.f,  -.3f, 0.f,
        0.f, 0.f, 0.f,
        
        0.f, 0.f, 0.f,
        .1f,  -.4f, 0.f,
        .2f, -.4f, 0.f,
        
        .2f, -.4f, 0.f,
        0.f, 0.f, 0.f,
        .25f, -0.25f, 0.f

    };
    size_t vertices_2_size = sizeof(vertices_2);
    
    Array_Draw ad;
    GLboolean is_running = true;
    
    SDL_Window* window = ad.Init_SDL("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    
    GLuint vertex_shader = ad.Create_vertex_shader();
    GLuint fragment_shader_up = ad.Create_fragment_shader(fragment_shader_source_up);
    GLuint fragment_shader_down = ad.Create_fragment_shader(fragment_shader_source_down);
    GLuint program_shader_up = ad.Create_program_shader_obj(vertex_shader, fragment_shader_up);
    GLuint program_shader_down = ad.Create_program_shader_obj(vertex_shader, fragment_shader_down);
    
    GLuint VAO = ad.Create_buffers(vertices, vertices_size);
    GLuint VAO_2 = ad.Create_buffers(vertices_2, vertices_2_size);
    
    SDL_Event _event;
    while(is_running)
    {
        if(SDL_PollEvent(&_event))
        {
            if(_event.type == SDL_KEYDOWN)
            {
                switch(_event.key.keysym.sym)
                {
                    case SDLK_q:
                        is_running = false;
                        break;
                    default:
                        break;
                }
            
            }
        }
        
        glClearColor(83.0/255.0, 82.0/255.0, 87.0/255.0, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(program_shader_up);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0,18);
        
        glUseProgram(program_shader_down);
        glBindVertexArray(VAO_2);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays(GL_TRIANGLES, 0,18);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBindVertexArray(0);
    
        SDL_GL_SwapWindow(window);
    }
    
    return 0;
}

















