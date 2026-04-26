#include "Board.h"

Board::Board(float *vertices, size_t vSize, unsigned int *indices, size_t iSize)
{
     squareMesh = std::make_unique<Mesh>(vertices, vSize, indices, iSize);

     for (int row = 0; row < 8; row++)
     {
          for (int col = 0; col < 8; col++)
          {
               tiles.emplace_back(row, col, squareMesh.get());
          }
     }
     tiles[8].piece = PieceType::BPAWN;
}

void Board::Draw(Shader &shader, Texture *pawnTexture)
{
     for (auto &tile : tiles)
     {
          tile.Draw(shader, pawnTexture);
     }
}

void Board::HandleClick(double xPos, double yPos, int windowWidth, int windowHeight)
{
     // Convert pixels to NDC (-1 to 1)
     float mouseNDC_X = (2.0f * (float)xPos) / windowWidth - 1.0f;
     float mouseNDC_Y = 1.0f - (2.0f * (float)yPos) / windowHeight;

     float aspect = (float)windowWidth / (float)windowHeight;
     float correctedX = mouseNDC_X * aspect;

     float startOffset = -0.8f;
     float tileSize = 0.2f;

     if (correctedX >= startOffset && correctedX <= (startOffset + 8 * tileSize) &&
         mouseNDC_Y >= startOffset && mouseNDC_Y <= (startOffset + 8 * tileSize))
     {
          int col = (int)((correctedX - startOffset) / tileSize);
          int row = (int)((mouseNDC_Y - startOffset) / tileSize);

          // Clamp just in case of float rounding at the very edge
          col = std::max(0, std::min(7, col));
          row = std::max(0, std::min(7, row));

          int clickIndex = row * 8 + col;

          if (selectedTileIndex != -1)
               tiles[selectedTileIndex].state = TileState::IDLE;

          if (clickIndex == selectedTileIndex)
               selectedTileIndex = -1;
          else
          {
               selectedTileIndex = clickIndex;
               tiles[selectedTileIndex].state = TileState::SELECTED;
          }
     }
}