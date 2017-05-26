#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Window
{
public:
  Window();
  ~Window();
  Window(const std::string& title, const sf::Vector2u& size);
  
  void BeginDraw();
  void EndDraw();
  
  void Update();
  
  bool isDone();
  bool isFullScreen();
  sf::Vector2u getWindowSize();
  //sf::RenderWindow * GetRenderWindow();
  sf::RenderWindow m_window;
  
  void ToggleFullScreen();
  void Draw(sf::Drawable& drawable);
private:
  void Setup(const std::string& title, const sf::Vector2u& size);
  
  void Destroy();
  void Create();
  
  //sf::RenderWindow m_window;
  sf::Vector2u m_windowSize;
  std::string m_windowTitle;
  bool m_isDone;
  bool m_isFullScreen;
  
};