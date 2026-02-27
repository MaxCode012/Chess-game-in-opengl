class Mesh
{
public:
     unsigned int VAO;
     int indexCount;

     Mesh(float *vertices, size_t vSize, unsigned int *indices, size_t iSize)
     {
          glGenVertexArrays(1, &VAO);
          glBindVertexArray(VAO);
          setupMesh(vertices, vSize, indices, iSize);
     }

     ~Mesh()
     {
          glDeleteVertexArrays(1, &VAO);
          glDeleteBuffers(1, &VBO);
          glDeleteBuffers(1, &EBO);
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
     unsigned int VBO, EBO;

     void setupMesh(float *vertices, size_t vSize, unsigned int *indices, size_t iSize)
     {
          // 1. Upload Vertex Data (VBO)
          glGenBuffers(1, &VBO);
          glBindBuffer(GL_ARRAY_BUFFER, VBO);
          glBufferData(GL_ARRAY_BUFFER, vSize, vertices, GL_STATIC_DRAW);

          // 2. Upload Index Data (EBO)
          indexCount = iSize / sizeof(unsigned int);
          glGenBuffers(1, &EBO);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
          glBufferData(GL_ELEMENT_ARRAY_BUFFER, iSize, indices, GL_STATIC_DRAW);

          // 3. Define Layout
          glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
          glEnableVertexAttribArray(0);

          // Note: VAO stores the EBO binding, but NOT the VBO unbinding.
          glBindVertexArray(0);
     }
};