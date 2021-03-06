#include "Snake.h"


Snake::Snake(int bodySize)
{
  m_size = bodySize;
  m_bodyRect.setSize(sf::Vector2f(m_size - 1, m_size - 1));
  Reset();
  
}

void Snake::Reset()
{
  m_snakeBody.clear();
  
  
  m_snakeBody.push_back(SnakeSegment(5,7));
  m_snakeBody.push_back(SnakeSegment(5,6));
  m_snakeBody.push_back(SnakeSegment(5,5));
  
  SetDirection(Direction::None);
  
  m_speed = 15;
  m_lives = 3;
  m_score = 0;
  m_lost = false;
  
}

void Snake::Extend()
{
  if ( m_snakeBody.empty() ){ return; }
  
  SnakeSegment& tail_head = m_snakeBody[m_snakeBody.size() - 1];
  
  if ( m_snakeBody.size() > 1 )
  {
    SnakeSegment& tail_bone = m_snakeBody[m_snakeBody.size() - 2];
    
    if (tail_bone.position.x == tail_head.position.x)
    {
      if (tail_bone.position.y > tail_head.position.y)
      {
	m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
      }
      else
      {
	m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
      }
    }
    else if (tail_bone.position.y == tail_head.position.y)
    {
      if (tail_bone.position.x > tail_head.position.x)
      {
	m_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
      }
      else
      {
	m_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
      }
    }
    
  }
  else // size==1
  {
    if (m_dir == Direction::Up)
    {
      m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
    }
    else if (m_dir == Direction::Down)
    {
      m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
    }
    else if (m_dir == Direction::Left)
    {
      m_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
    }
    else if (m_dir == Direction::Right)
    {
      m_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
    }
  }
  
}

void Snake::Tick()
{
  if (m_snakeBody.empty()) { return; }
  
  if (m_dir == Direction::None) { return; }
  
  Move();
  
  CheckCollisions();
}

void Snake::Move()
{
  for (int i = m_snakeBody.size() - 1; i > 0; --i)
  {
    m_snakeBody[i].position = m_snakeBody[i - 1].position;
  }
  
  if (m_dir == Direction::Down)
  {
    ++m_snakeBody[0].position.y;
  }
  if (m_dir == Direction::Up)
  {
    --m_snakeBody[0].position.y;
  }
  if (m_dir == Direction::Left)
  {
    --m_snakeBody[0].position.x;
  }
  if (m_dir == Direction::Right)
  {
    ++m_snakeBody[0].position.x;
  }
  
  
  
}

void Snake::CheckCollisions()
{
  if ( m_snakeBody.size() < 5 ) { return; }
  
  SnakeSegment& head = m_snakeBody.front();
  
  for (auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); ++itr)
  {
    if (itr->position == head.position) // snake segment collides with the head
    {
      int segments = m_snakeBody.end() - itr;
      Cut(segments);
      break;
    }
  }
}

void Snake::Cut(int segments)
{
  for (int i = 0; i < segments; ++i)
  {
    m_snakeBody.pop_back();
  }
  --m_lives;
  
  if (!m_lives) { Lose(); return;}
}

void Snake::Render(sf::RenderWindow& window)
{
  if (m_snakeBody.empty()) { return; }
  
  auto head = m_snakeBody.begin();
  
  m_bodyRect.setFillColor(sf::Color::Yellow);
  
  m_bodyRect.setPosition(head->position.x * m_size, head->position.y * m_size);
  
  window.draw(m_bodyRect);
  
  m_bodyRect.setFillColor(sf::Color::Green);
  
  for (auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); ++itr)
  {
    m_bodyRect.setPosition(itr->position.x * m_size, itr->position.y * m_size);
    
    window.draw(m_bodyRect);
  }
  
}

Direction Snake::GetPhysicalDirection()
{
  if (m_snakeBody.size() <= 1)
  {
    return Direction::None;
  }
  
  SnakeSegment& head = m_snakeBody[0];
  SnakeSegment& neck = m_snakeBody[1];
  
  if(neck.position.x == head.position.x)
  {
    return (head.position.y > neck.position.y ? Direction::Down : Direction::Up);
  }
  else if(neck.position.y == head.position.y)
  {
    return (head.position.x > neck.position.y ? Direction::Right : Direction::Left);
  }
  
  return Direction::None;
}






