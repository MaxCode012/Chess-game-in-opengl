#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Board/Board.h"
#include "Shader/Shader.h"
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

     bool isRunning;
     bool mouseWasPressed;

     void ProcessInput();
     void Update();
     void Render();
};