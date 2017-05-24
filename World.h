#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Snake.h"

class Window
{
public:
  Wrold(sf::Vector2u windSize);
  ~World();
  
  int GetBlockSize() { return m_blockSize; }
  
  void RespawnApple();
  
  void Update(Snake& player);
  void Render(sf::RenderWindow& window);
  
private:
  sf::Vector2u m_WindowSize;
  sf::Vector2i m_item;
  
  int m_blockSize;
  
  sf::CircleShape m_appleShape;
  sf::RectangleShape m_bounds[4];
  
};