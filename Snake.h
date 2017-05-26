#pragma once
#include <SFML/Graphics.hpp>

struct SnakeSegment
{
  SnakeSegment(int x, int y):position(x,y){}
  sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction {None, Up, Down, Left, Right};

class Snake
{
public:
  Snake(int bodySize);
  ~Snake() {}
  
  void SetDirection(Direction dir) {m_dir = dir;}
  Direction getDirection() {return m_dir;}
  int GetSpeed() {return m_speed;}
  int GetLives() {return m_lives;}
  int GetScore() {return m_score;}
  void IncreaseScore() {m_score += 10;}
  sf::Vector2i GetPosition()
  {
    return ( !m_snakeBody.empty() ? m_snakeBody.front().position : sf::Vector2i(1,1)); 
  }
  bool HasLost() {return m_lost;}
  
  void Lose() {m_lost = true;}
  void ToggleLost() {m_lost = !m_lost;}
  
  void Extend(); //grow the snake
  void Reset(); //reset the snake
  
  void Move();
  void Tick();
  
  void Cut(int segments);
  
  void Render(sf::RenderWindow& window);
  
  
private:
  void CheckCollisions();
  
  SnakeContainer m_snakeBody;
  int m_size; // size of the Graphics?
  Direction m_dir; 
  
  int m_speed;
  int m_lives;
  int m_score;
  bool m_lost;
  sf::RectangleShape m_bodyRect; //shape used in rendering
  
};