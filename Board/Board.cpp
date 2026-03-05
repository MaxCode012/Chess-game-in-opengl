#include "Board.h"

Board::Board(float *vertices, size_t vSize, unsigned int *indices, size_t iSize)
{
     squareMesh = new Mesh(vertices, vSize, indices, iSize);

     for (int row = 0; row < 8; row++)
     {
          for (int col = 0; col < 8; col++)
          {
               tiles.emplace_back(row, col, squareMesh);
          }
     }
}

Board::~Board()
{
     delete squareMesh;
}

void Board::Draw(Shader &shader)
{
     for (int i = 0; i < 64; i++)
     {
          tiles[i].Draw(shader);
     }
}