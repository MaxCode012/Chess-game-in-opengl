#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader/Shader.h"
#include "Mesh.h"

// clang-format off
float vertices[9] = {
     -1.0f, -1.0f, 0.0f,  //Left
     +0.0f, +1.0f, 0.0f,  //Middle
     +1.0f, -1.0f, 0.0f,  //Right
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

     Mesh triangle(vertices, sizeof(vertices));
     triangle.unbind();

     Shader shader("Shader/vertex.glsl", "Shader/fragment.glsl");

     while (!glfwWindowShouldClose(window))
     {
          glClear(GL_COLOR_BUFFER_BIT);

          shader.use();
          triangle.bind();

          glDrawArrays(GL_TRIANGLES, 0, triangle.vertCount);

          glfwSwapBuffers(window);
          glfwPollEvents();
     }
     glfwTerminate();
     return 0;
}