#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader/Shader.h"
#include "Mesh.h"
#include "Board/Board.h"

// clang-format off
float vertices[] = {
    1.0f, 1.0f, 0.0f,  // Top Right
    1.0f, 0.0f, 0.0f,  // Bottom Right
    0.0f, 0.0f, 0.0f,  // Bottom Left
    0.0f, 1.0f, 0.0f   // Top Left 
};

unsigned int indices[] = 
{
     0, 1, 3,
     1, 2, 3
};
// clang-format on

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
     // Adjust the OpenGL viewport to the new window size
     glViewport(0, 0, width, height);
};

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
     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
     {
          std::cout << "Failed to initialize GLAD" << std::endl;
          return -1;
     }

     Shader shader("Shader/vertex.glsl", "Shader/fragment.glsl");
     shader.use();

     shader.setVec3("squareColor", 0.0f, 0.0f, 0.0f);
     Board board(vertices, sizeof(vertices), indices, sizeof(indices));

     while (!glfwWindowShouldClose(window))
     {
          int width, height;
          glfwGetFramebufferSize(window, &width, &height);

          glClearColor(30.0f / 255.0f, 30.0f / 255.0f, 30.0f / 255.0f, 1.0f);
          glClear(GL_COLOR_BUFFER_BIT);

          float aspect = (height > 0) ? (float)width / (float)height : 1.0f;
          shader.use();
          shader.setFloat("aspect", aspect);
          board.Draw(shader);

          glfwSwapBuffers(window);
          glfwPollEvents();
     }
     glfwTerminate();
     return 0;
}