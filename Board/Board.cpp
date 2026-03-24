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
}

void Board::Draw(Shader &shader)
{
     for (auto &tile : tiles)
     {
          tile.Draw(shader);
     }
}

void Board::HandleClick(double xPos, double yPos, int windowWidth, int windowHeight)
{
     float xPercent = (float)xPos / windowWidth;
     float yPercent = (float)yPos / windowHeight;

     yPercent = 1.0f - yPercent;

     float boardLeft = 0.2f;
     float boardRight = 0.8f;
     float boardTop = 0.9f;
     float boardBottom = 0.1f;

     float boardWidthX = boardRight - boardLeft;
     float boardWidthY = boardTop - boardBottom;

     if (xPercent > boardLeft && xPercent <= boardRight && yPercent >= boardBottom && yPercent <= boardTop)
     {
          float relativeX = xPercent - boardLeft;
          float relativeY = yPercent - boardBottom;

          // floats 0.0 - 1.0
          float normalizedX = relativeX / boardWidthX;
          float normalizedY = relativeY / boardWidthY;

          // numbers 0 - 7
          int col = normalizedX * 8;
          int row = normalizedY * 8;

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
