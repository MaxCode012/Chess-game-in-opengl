#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Board/Board.h"
#include "Shader/Shader.h"
#include "Texture/Texture.h"
#include <iostream>
#include <memory>

class Game
{
public:
     Game();
     ~Game();

     bool Initialize(int width, int height, const char *title);
     void Run();

private:
     GLFWwindow *window;
     std::unique_ptr<Board> board;
     std::unique_ptr<Shader> shader;
     std::unique_ptr<Texture> pawnTexture;

     bool isRunning;
     bool mouseWasPressed;

     void ProcessInput();
     void Update();
     void Render();
};