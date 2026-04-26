#pragma once
#include <vector>
#include <memory>

#include "../Mesh.h"
#include "../Shader/Shader.h"
#include "../Tile/Tile.h"

class Board
{
public:
     Board::Board(float *vertices, size_t vSize, unsigned int *indices, size_t iSize);
     ~Board() = default;

     void Draw(Shader &shader, Texture *pawnTexture);
     void HandleClick(double xPos, double yPos, int windowWidth, int windowHeight);

private:
     std::unique_ptr<Mesh> squareMesh; // one pointer instead of 64 mesh objects saves lots of memory with a total of 8 bytes
     std::vector<Tile> tiles;
     int selectedTileIndex = -1;
};