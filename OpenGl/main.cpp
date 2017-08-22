#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


int main(int argc, char* argv[])
{
    const GLuint WIDTH = 800;
    const GLuint HEIGHT = 600;
    
    SDL_Event _event;
    GLboolean is_running = GL_TRUE;
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 7);
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("OpenGL/MAC OSX", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    auto context = SDL_GL_CreateContext(window);
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    glViewport(0, 0, WIDTH, HEIGHT);
 
    const GLfloat vertices[]=
    {
        -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.0f,
        1.0f, 0.0f, 0.0f
    };
    
    
    const GLchar* vertex_shader_source =
    "#version 330 core\n"
    "layout(location =0) in vec3 position;\n"
    "void main(void){\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0f);\n"
    "}\0";
    
    const GLchar* fragment_shader_source =
    "#version 330 core\n"
    "out vec4 color;\n"
    "void main(void){\n"
    "color = vec4(0.9f, 0.2f, 0.4f, 1.0f);\n"
    "}\0";
    
    GLuint vertex_shader= glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    
    GLint success;
    GLchar log_info[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, log_info);
        std::cout<<"Vertex shader compile failed: " << log_info << std::endl;
    }
    
    
    GLint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, log_info);
        std::cout<<"Fragment shader failed to compile: " << log_info << std::endl;
    }
    
    
    GLint program_object = glCreateProgram();
    glAttachShader(program_object, vertex_shader);
    glAttachShader(program_object, fragment_shader);
    glLinkProgram(program_object);
    
    glGetProgramiv(program_object, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(program_object, 512, NULL, log_info);
        std::cout<<"Program linking failed: " << log_info << std::endl;
    }
    else
    {
        glDeleteShader(fragment_shader);
        glDeleteShader(vertex_shader);
    }
    
    
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while(is_running)
    {
        if(SDL_PollEvent(&_event))
        {
            if(_event.type == SDL_KEYDOWN)
            {
                switch (_event.key.keysym.sym) {
                    case SDLK_q:
                        is_running = GL_FALSE;
                        break;
                    default:
                        break;
                }
            }
        }
        
        glClearColor(0.8f, 0.9f, 0.9f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(program_object);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
        
        SDL_GL_SwapWindow(window);
    }
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    
    
    return 0;
}

















