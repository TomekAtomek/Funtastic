#include "World.h"

World::World(sf::Vector2u windSize)
{
  m_blockSize = 16;
  
  m_WindowSize = windSize;
  
  
  RespawnApple();
  
  m_appleShape.setFillColor(sf::Color::Red);
  m_appleShape.setRadius(m_blockSize / 2);
  
  for (int i = 0; i < 4; ++i)
  {
    m_bounds[i].setFillColor(sf::Color(150,0,0));
    
    if(!((i+1)%2)) //odd
    {
      m_bounds[i].setSize(sf::Vector2f(m_WindowSize.x, m_blockSize));
    }
    else
    {
      m_bounds[i].setSize(sf::Vector2f(m_blockSize, m_WindowSize.y));
    }
    
    if (i < 2)
    {
      m_bounds[i].setPosition(0,0);
    }
    else
    {
      m_bounds[i].setPosition(sf::Vector2f(m_WindowSize));
      m_bounds[i].setOrigin(m_bounds[i].getSize());
    }
    
  }
}


void World::RespawnApple()
{
  int maxX = (m_WindowSize.x / m_blockSize) - 2;
  int maxY = (m_WindowSize.y / m_blockSize) - 2;
  
  m_item = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
  
  m_appleShape.setPosition(m_item.x * m_blockSize, m_item.y * m_blockSize);
  
}

void World::Update(Snake& player)
{
  if (player.GetPosition() == m_item)
  {
     player.Extend();
     player.IncreaseScore();
     RespawnApple();
  }
  
  int gridSizeX = m_WindowSize.x / m_blockSize;
  int gridSizeY = m_WindowSize.y / m_blockSize;
  
  int playerX = player.GetPosition().x;
  int playerY = player.GetPosition().y;
  
  
  if (playerX <= 0 || playerX >= gridSizeX - 1 || playerY <= 0 || playerY >= gridSizeY - 1)
  {
    player.Lose();
  }
  
  
}

void World::Render(sf::RenderWindow& window)
{
  for (int i = 0; i < 4; ++i)
  {
     window.draw(m_bounds[i]);
  }
  
  window.draw(m_appleShape);
}

