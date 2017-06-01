#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


using MessageContainer = std::vector<std::string>;

class TextBox
{
public:
  TextBox();
  TextBox(int visible, int charSize, int width, sf::Vector2f screenPos);
  ~TextBox();
  
  void Setup(int visible, int charSize, int width, sf::Vector2f screenPos);
  void Clear();
  void Add(std::string message);
  
  void Render(sf::RenderWindow& wind);
  
private:
  MessageContainer m_messages;
  int m_numVisible;
  
  sf::RectangleShape m_backdrop;
  sf::Font m_font;
  sf::Text m_content;
};