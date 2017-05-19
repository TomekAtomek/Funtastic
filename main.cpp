#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
using namespace sf;

int main()
{
    Game game;
    
    while(!game.GetWindow()->isDone())
    {
      game.HandleInput();
      game.Update();
      game.Render();
      game.RestartClock();
    }

    return 0;
}
