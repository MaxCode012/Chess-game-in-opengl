#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader/Shader.h"
#include "Mesh.h"

// clang-format off
float vertices[] = {
     0.5f,  0.5f, 0.0f,  
     0.5f, -0.5f, 0.0f,  
    -0.5f, -0.5f, 0.0f, 
    -0.5f,  0.5f, 0.0f  
};

unsigned int indices[] = 
{
     0, 1, 3,
     1, 2, 3
};
// clang-format on

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

     Mesh square(vertices, sizeof(vertices), indices, sizeof(indices));
     square.unbind();

     Shader shader("Shader/vertex.glsl", "Shader/fragment.glsl");

     while (!glfwWindowShouldClose(window))
     {
          glClear(GL_COLOR_BUFFER_BIT);

          shader.use();
          square.bind();

          glDrawElements(GL_TRIANGLES, square.indexCount, GL_UNSIGNED_INT, 0);

          glfwSwapBuffers(window);
          glfwPollEvents();
     }
     glfwTerminate();
     return 0;
}