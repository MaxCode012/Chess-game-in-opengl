#include "Game.h"

int main()
{
     Game chessGame;

     if (chessGame.Initialize(640, 480, "Chess Game"))
     {
          chessGame.Run();
     }

     return 0;
}