#pragma once
#include <glad/glad.h>

class Mesh
{
public:
     unsigned int VAO;
     int vertCount;

     Mesh(float *vertices, size_t size)
     {
          glGenVertexArrays(1, &VAO);
          glBindVertexArray(VAO);

          setupMesh(vertices, size);
     }
     ~Mesh()
     {
          glDeleteVertexArrays(1, &VAO);
          glDeleteBuffers(1, &VBO);
     }

     void bind() const
     {
          glBindVertexArray(VAO);
     }

     void unbind() const
     {
          glBindVertexArray(0);
     }

private:
     unsigned int VBO;

     void setupMesh(float *vertices, size_t size)
     {
          vertCount = size / (sizeof(float) * 3);

          glGenBuffers(1, &VBO);
          glBindBuffer(GL_ARRAY_BUFFER, VBO);
          glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
          glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void *)0);
          glEnableVertexAttribArray(0);
     }
};