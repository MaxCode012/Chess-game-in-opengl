#pragma once
#include "../Mesh.h"
#include "../Shader/Shader.h"

class Board
{
public:
     Board::Board(float *vertices, size_t vSize, unsigned int *indices, size_t iSize);
     ~Board();
     void Draw(Shader &shader);

private:
     Mesh *squareMesh;
     float tileSize = 0.2f;
     float startOffset = -0.8f;
};