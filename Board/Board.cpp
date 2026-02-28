#include "Board.h"

Board::Board(float *vertices, size_t vSize, unsigned int *indices, size_t iSize)
{
     squareMesh = new Mesh(vertices, vSize, indices, iSize);
}

Board::~Board()
{
     delete squareMesh;
}

void Board::Draw(Shader &shader)
{
     squareMesh->bind();

     for (int row = 0; row < 8; row++)
     {
          for (int col = 0; col < 8; col++)
          {
               float x = startOffset + col * tileSize;
               float y = startOffset + row * tileSize;
               shader.setVec2("offset", x, y);

               if ((row + col) % 2 == 0)
               {
                    shader.setVec3("squareColor", 0.8f, 0.8f, 0.7f);
               }
               else
               {
                    shader.setVec3("squareColor", 0.2f, 0.4f, 0.2f);
               }
               glDrawElements(GL_TRIANGLES, squareMesh->indexCount, GL_UNSIGNED_INT, 0);
          }
     }
}