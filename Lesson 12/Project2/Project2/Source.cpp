#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(30.f);
    shape.setFillColor(sf::Color::Green);

    

	/*if (!texture.create(100, 100))
	{

	}*/
	
    sf::Texture texture;
    texture.loadFromFile("Textures\\texture.png");
    texture.setSmooth(true);

    sf::Sprite sprite(texture);
    sprite.setScale(0.1f, 0.1f);
    sprite.setPosition(100, 100);
    auto rect = sprite.getTextureRect();
    sprite.setOrigin(rect.width / 2, rect.height / 2);

	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        	
        	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        	{
                auto pos = shape.getPosition();
                pos.x -= 5;
                shape.setPosition(pos);
                std::cout << "Left" << std::endl;
        	}
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                //auto pos = sprite.getPosition();
                sprite.move(5, 0);
                sprite.rotate(15);

                std::cout << "Left" << std::endl;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                auto pos = shape.getPosition();
                pos.y -= 5;
                shape.setPosition(pos);

                std::cout << "Left" << std::endl;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                auto pos = shape.getPosition();
                pos.y += 5;
                shape.setPosition(pos);

                std::cout << "Left" << std::endl;
            }
        }

        window.clear();
    	
        window.draw(sprite);

        //window.draw(shape);
        window.display();
    }

	return 0;
}