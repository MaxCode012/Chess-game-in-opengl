#include "Tile.h";

Tile::Tile(int row, int col, Mesh *sharedMesh) : m_mesh(sharedMesh)
{
     float x = startOffset + (col * tileSize);
     float y = startOffset + (row * tileSize);
     this->m_worldPos = glm::vec2(x, y);

     if ((row + col) % 2 == 0)
     {
          this->m_baseColor = glm::vec3(0.8f, 0.8f, 0.7f);
     }
     else
     {
          this->m_baseColor = glm::vec3(0.2f, 0.4f, 0.2f);
     }
}

void Tile::Draw(Shader &shader)
{
     shader.setVec2("offset", m_worldPos.x, m_worldPos.y);
     shader.setVec3("squareColor", m_baseColor.r, m_baseColor.g, m_baseColor.b);

     m_mesh->bind();
     glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
