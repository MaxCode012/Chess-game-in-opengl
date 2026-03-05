#pragma once
#include "../Mesh.h"
#include "../Shader/Shader.h"
#include "../Tile/Tile.h"
#include <vector>

class Board
{
public:
     Board::Board(float *vertices, size_t vSize, unsigned int *indices, size_t iSize);
     ~Board();
     void Draw(Shader &shader);

private:
     Mesh *squareMesh;
     std::vector<Tile> tiles;
};