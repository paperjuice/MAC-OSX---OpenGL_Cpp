# MAC-OSX---OpenGL_Cpp

# 1. Single fragment shader 
- SDL used to draw window and take user input ( 'q' for closing the window)
- one fragment shader
- one vertex shader
- array draw used
![](http://i.imgur.com/ky6EZZZ.png "Array Draw")

# 2. Two fragment shaders, two vertex array buffers
- one VAO for the top heart and one for the below heart
- the heart above uses glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
- the heart below uses glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
![](http://i.imgur.com/2XP0lmM.png "Array Draw")
