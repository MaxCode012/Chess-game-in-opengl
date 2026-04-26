#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "Mesh.h"
#include "Shader/Shader.h"
#include "Texture/Texture.h"

enum class TileState
{
     IDLE,
     SELECTED,
     VALID_TARGET
};

enum class PieceType
{
     NONE,
     WPAWN,
     WBISHOP,
     WROOK,
     WKNIGHT,
     WKING,
     WQUEEN,
     BPAWN,
     BBISHOP,
     BROOK,
     BKNIGHT,
     BKING,
     BQUEEN
};

class Tile
{
public:
     Tile(int row, int col, Mesh *sharedMesh);

     void Draw(Shader &shader, Texture *pieceTexture);

     bool isEmpty = true;
     TileState state = TileState::IDLE;
     PieceType piece = PieceType::NONE;

private:
     Mesh *m_mesh;

     glm::vec2 m_worldPos;
     glm::vec3 m_baseColor;

     // Constants for calculation
     const float tileSize = 0.2f;
     const float startOffset = -0.8f;
};