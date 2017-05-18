#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main()
{
    std::string myTitle("MyGame!");
    RenderWindow window(VideoMode(640, 480), myTitle);
    //CircleShape shape(100.f);
    //shape.setFillColor(Color::Red);

    RectangleShape shape(Vector2f(128.0f,128.0f));

    shape.setFillColor(Color::Green);
    
    auto xPos = 300;
    auto yPos = 240;

    shape.setPosition(xPos,yPos);

    shape.setOrigin(shape.getSize().x, shape.getSize().y); //a comment
    
    sf::Texture mushroomTexture;
    
    if (!mushroomTexture.loadFromFile("Mushroom.png"))
    {
      std::cout<<"Error loading png" << std::endl;
    }
    
    sf::Sprite mushroom(mushroomTexture);
    
    sf::Vector2u size = mushroomTexture.getSize();
    
    mushroom.setOrigin(size.x / 2, size.y / 2);
    
    sf::Vector2f increment(0.4f, 0.4f);
    
    

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        if((mushroom.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0) || 
           (mushroom.getPosition().x - (size.x / 2) < 0 && increment.x < 0))
        {        // Reverse the direction on X axis.        
          increment.x = -increment.x;
	  mushroom.setColor(sf::Color(255, 0, 0, 255)); // Red tint
        }    

        if((mushroom.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0) || 
	  (mushroom.getPosition().y - (size.y / 2) < 0 && increment.y < 0))    
        {         // Reverse the direction on Y axis.        
          increment.y = -increment.y;
	  mushroom.setColor(sf::Color(0, 0, 0, 255)); // Red tint
        }
        
        mushroom.setPosition(mushroom.getPosition() + increment);

        window.clear(sf::Color(16,16,16,255)); // Dark gray.
        window.draw(mushroom);
        window.display();
    }

    return 0;
}
