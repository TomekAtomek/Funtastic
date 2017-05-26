#include "Window.h"

Window::Window()
{ 
  Setup("Window", sf::Vector2u(640, 480));
}
Window::~Window()
{
  Destroy();
}
Window::Window(const std::string& title, const sf::Vector2u& size)
{
  Setup(title, size);
}
  
void Window::BeginDraw()
{
  m_window.clear(sf::Color::Black);
}
void Window::EndDraw()
{
  m_window.display();
}
  
void Window::Update()
{
  sf::Event event;
  
  while(m_window.pollEvent(event))
  {
    if(event.type == sf::Event::Closed)
    {
      m_isDone = true;
    }
    else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
    {
      ToggleFullScreen();
    }
  }
}
  
bool Window::isDone(){ return m_isDone;}
bool Window::isFullScreen(){return m_isFullScreen;}
sf::Vector2u Window::getWindowSize(){ return m_windowSize;}
  
void Window::ToggleFullScreen()
{
  m_isFullScreen = !m_isFullScreen;
  Destroy();
  Create();
}
void Window::Draw(sf::Drawable& drawable)
{
  m_window.draw(drawable);
}

void Window::Setup(const std::string& title, const sf::Vector2u& size)
{
  m_windowTitle = title;
  m_windowSize = size;
  m_isDone = false;
  m_isFullScreen = false;
  this->Create();
}
  
void Window::Destroy()
{
  m_window.close();
}
void Window::Create()
{
  auto style = (m_isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
  
  m_window.create({m_windowSize.x,m_windowSize.y,32},m_windowTitle,style);
}

/*sf::RenderWindow* Window::GetRenderWindow()
{
  return &m_window;
}*/
