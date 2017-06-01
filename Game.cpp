#include "Game.h"


Game::Game():m_Window("MushroomFun", sf::Vector2u(800,600)), m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800,600))
{
  srand(std::time(nullptr));
  m_MushroomTexture.loadFromFile("Mushroom.png");
  m_MushroomSprite.setTexture(m_MushroomTexture);
  m_increment = sf::Vector2i(400,400);
  m_textbox.Setup(5, 14, 350, sf::Vector2f(225,0));
  m_textbox.Add("Seeded random number generator with: " + std::to_string(std::time(nullptr)));
  m_elapsed = 0.0f;
}

Game::~Game()
{

}

void Game::Update()
{
  m_Window.Update();
  //this->MoveMushroom();
  float timestep = 1.0f / m_snake.GetSpeed();
  
  if(m_elapsed >= timestep)
  {
    m_snake.Tick();
    m_world.Update(m_snake);
    m_elapsed -= timestep;
    if(m_snake.HasLost())
    {
      m_snake.Reset();
    }
  }
  
}

/*void Game::MoveMushroom()
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
  
}*/

void Game::Render()
{
  m_Window.BeginDraw();
  //m_Window.Draw(m_MushroomSprite);
  
  //m_world.Render(*m_Window.GetRenderWindow());
  //m_snake.Render(*m_Window.GetRenderWindow());
  m_world.Render(m_Window.m_window);
  m_snake.Render(m_Window.m_window);
  m_textbox.Render(m_Window.m_window);
  
  m_Window.EndDraw();
}

void Game::HandleInput()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetPhysicalDirection() != Direction::Down)
  {
    m_snake.SetDirection(Direction::Up);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetPhysicalDirection() != Direction::Up)
  {
    m_snake.SetDirection(Direction::Down);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetPhysicalDirection() != Direction::Left)
  {
    m_snake.SetDirection(Direction::Right);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetPhysicalDirection() != Direction::Right)
  {
    m_snake.SetDirection(Direction::Left);
  }
}

Window* Game::GetWindow()
{
  return &m_Window;
}

sf::Time Game::GetTimeElapsed()
{
  return m_clock.getElapsedTime();
}

void Game::RestartClock()
{
  m_elapsed += m_clock.restart().asSeconds();
}






