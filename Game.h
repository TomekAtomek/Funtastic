#pragma once
#include "Window.h"

#include "World.h"
#include "Snake.h"

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
  float m_elapsed;
  
  World m_world;
  Snake m_snake;
};