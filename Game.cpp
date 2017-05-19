#include "Game.h"


Game::Game():m_Window("MushroomFun", sf::Vector2u(800,600))
{
  m_MushroomTexture.loadFromFile("Mushroom.png");
  m_MushroomSprite.setTexture(m_MushroomTexture);
  m_increment = sf::Vector2i(400,400);
}

Game::~Game()
{

}

void Game::Update()
{
  m_Window.Update();
  this->MoveMushroom();
}

void Game::MoveMushroom()
{
  sf::Vector2u windowSize = m_Window.getWindowSize();   
  sf::Vector2u textureSize = m_MushroomTexture.getSize();
  
  if((m_MushroomSprite.getPosition().x > windowSize.x - textureSize.x && m_increment.x > 0)||
    (m_MushroomSprite.getPosition().x < 0 && m_increment.x < 0))
  {
    m_increment.x = -m_increment.x;
  }
  
  if((m_MushroomSprite.getPosition().y > windowSize.y - textureSize.y && m_increment.y > 0)||
    (m_MushroomSprite.getPosition().y < 0 && m_increment.y < 0))
  {
    m_increment.y = -m_increment.y;
  }
  
  float timeElapsed = m_elapsed.asSeconds();
  
  m_MushroomSprite.setPosition(
    m_MushroomSprite.getPosition().x + (m_increment.x * timeElapsed), 
    m_MushroomSprite.getPosition().y + (m_increment.y * timeElapsed));
  
}

void Game::Render()
{
  m_Window.BeginDraw();
  m_Window.Draw(m_MushroomSprite);
  m_Window.EndDraw();
}

void Game::HandleInput()
{

}

Window* Game::GetWindow()
{
  return &m_Window;
}

sf::Time Game::GetTimeElapsed()
{
  return m_elapsed;
}

void Game::RestartClock()
{
  m_elapsed += m_clock.restart();
}






