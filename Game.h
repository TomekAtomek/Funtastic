#pragma once
#include "Window.h"
class Game
{
public:
  Game();
  ~Game();
  
  void HandleInput();
  void Update();
  void Render();
  Window* GetWindow();
  sf::Time GetTimeElapsed();
  void RestartClock();

private:
  Window m_Window;
  void MoveMushroom();
  sf::Texture m_MushroomTexture;
  sf::Sprite m_MushroomSprite;
  sf::Vector2i m_increment;
  sf::Clock m_clock;
  sf::Time m_elapsed;
};