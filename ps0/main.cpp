#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::Vector2f vect(100.0f, 100.0f);
    sf::Sprite sprite;
    sf::Texture spriteText;
    sprite.setPosition(vect);
    if (spriteText.loadFromFile("Pixel-Art-PNG-Isolated-File.png") == false)
        return EXIT_FAILURE;
    sprite.setTexture(spriteText);
    while (window.isOpen()) {
        sf::Event event;
    float angle = 0;
        while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
           window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
          sprite.move(-3.0f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
          sprite.move(0.0f, -3.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
          sprite.move(0.0f, 3.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
          sprite.move(3.0f, 0.0f);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          angle += 90;
          sprite.rotate(angle);
        }
    window.clear();
    window.draw(sprite);
    window.display();
    }
    return 0;
}

