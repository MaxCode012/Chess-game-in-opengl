#include "Game.h"

// clang-format off
float vertices[] = {
    1.0f, 1.0f, 0.0f,  // Top Right
    1.0f, 0.0f, 0.0f,  // Bottom Right
    0.0f, 0.0f, 0.0f,  // Bottom Left
    0.0f, 1.0f, 0.0f   // Top Left 
};

unsigned int indices[] = 
{
     0, 1, 3,
     1, 2, 3
};
// clang-format on

Game::Game() : window(nullptr), board(nullptr), shader(nullptr), isRunning(false), mouseWasPressed(false)
{
}

bool Game::Initialize(int width, int height, const char *title)
{
     if (!glfwInit())
          return false;

     window = glfwCreateWindow(width, height, title, NULL, NULL);
     if (!window)
          return false;

     glfwMakeContextCurrent(window);
     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
          return false;

     shader = std::make_unique<Shader>("Shader/vertex.glsl", "Shader/fragment.glsl");
     board = std::make_unique<Board>(vertices, sizeof(vertices), indices, sizeof(indices));

     isRunning = true;
     return true;
}

void Game::ProcessInput()
{
     int leftState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);

     if (leftState == GLFW_PRESS && !mouseWasPressed)
     {
          mouseWasPressed = true;
          double x, y;
          int w, h;
          glfwGetCursorPos(window, &x, &y);
          glfwGetWindowSize(window, &w, &h);
          board->HandleClick(x, y, w, h);
     }
     else if (leftState == GLFW_RELEASE)
     {
          mouseWasPressed = false;
     }
}

void Game::Update()
{
}

void Game::Render()
{
     glClearColor(30.0f / 255.0f, 30.0f / 255.0f, 30.0f / 255.0f, 1.0f);
     glClear(GL_COLOR_BUFFER_BIT);

     int w, h;
     glfwGetFramebufferSize(window, &w, &h);
     glViewport(0, 0, w, h);
     glfwGetFramebufferSize(window, &w, &h);
     float aspect = (h > 0) ? (float)w / (float)h : 1.0f;
     shader->use();
     shader->setFloat("aspect", aspect);
     board->Draw(*shader);

     glfwSwapBuffers(window);
}

void Game::Run()
{
     while (isRunning && !glfwWindowShouldClose(window))
     {
          ProcessInput();
          Update();
          Render();
          glfwPollEvents();
     }
}

Game::~Game()
{
     glfwTerminate();
}