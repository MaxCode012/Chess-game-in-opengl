#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// clang-format off
float vertices[9] = {
     -1.0f, -1.0f, 0.0f,  //Left
     +0.0f, +1.0f, 0.0f,  //Middle
     +1.0f, -1.0f, 0.0f,  //Right
};
// clang-format on

std::string vertexShaderCode = R"glsl(
    #version 330 core
    layout (location = 0) in vec3 aPos;

    void main()
    {
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    }
)glsl";

std::string fragmentShaderCode = R"glsl(
    #version 330 core
    out vec4 FragColor;

    void main()
    {
        FragColor = vec4(0.5f, 0.0f, 0.5f, 1.0f);
    }
)glsl";

int main()
{
     GLFWwindow *window;

     if (!glfwInit())
          return -1;

     window = glfwCreateWindow(640, 480, "Chess game", NULL, NULL);

     if (!window)
     {
          glfwTerminate();
          return -1;
     }

     glfwMakeContextCurrent(window);

     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
     {
          std::cout << "Failed to initialize GLAD" << std::endl;
          return -1;
     }

     GLuint vertexBuff, vao;
     glGenVertexArrays(1, &vao);
     glGenBuffers(1, &vertexBuff);

     glBindVertexArray(vao);
     glBindBuffer(GL_ARRAY_BUFFER, vertexBuff);

     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
     glEnableVertexAttribArray(0);

     glBindVertexArray(0);

     const char *shaderSource = vertexShaderCode.c_str();
     GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
     glShaderSource(vertexShader, 1, &shaderSource, NULL);
     glCompileShader(vertexShader);

     const char *fragmentSource = fragmentShaderCode.c_str();
     GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
     glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
     glCompileShader(fragmentShader);

     GLuint program = glCreateProgram();
     glAttachShader(program, vertexShader);
     glAttachShader(program, fragmentShader);

     glLinkProgram(program);

     while (!glfwWindowShouldClose(window))
     {
          glClear(GL_COLOR_BUFFER_BIT);

          glUseProgram(program);
          glBindVertexArray(vao);

          glDrawArrays(GL_TRIANGLES, 0, 3);

          glfwSwapBuffers(window);
          glfwPollEvents();
     }
     glfwTerminate();
     return 0;
}