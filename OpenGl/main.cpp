#include <iostream>
#include "array_draw.hpp"



int main(int argc, char* argv[])
{
    Array_Draw ad;
    GLboolean is_running = true;
    
    SDL_Window* window = ad.Init_SDL("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    
    GLuint vertex_shader = ad.Create_vertex_shader();
    GLuint fragment_shader = ad.Create_fragment_shader();
    GLuint program_shader = ad.Create_program_shader_obj(vertex_shader, fragment_shader);
    
    GLuint VAO = ad.Create_buffers();
    
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
        
        glUseProgram(program_shader);
        glBindVertexArray(VAO);
        
        glDrawArrays(GL_TRIANGLES, 0,18);
        
        glBindVertexArray(0);
    
        SDL_GL_SwapWindow(window);
    }
    
    return 0;
}

















