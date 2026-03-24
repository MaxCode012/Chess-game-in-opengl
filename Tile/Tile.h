#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "Mesh.h"
#include "Shader/Shader.h"

enum class TileState
{
     IDLE,
     SELECTED,
     VALID_TARGET
};

class Tile
{
public:
     Tile(int row, int col, Mesh *sharedMesh);

     void Draw(Shader &shader);

     bool isEmpty = true;
     TileState state = TileState::IDLE;

private:
     Mesh *m_mesh;

     glm::vec2 m_worldPos;
     glm::vec3 m_baseColor;

     // Constants for calculation
     const float tileSize = 0.2f;
     const float startOffset = -0.8f;
};