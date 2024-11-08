// Copyright 2024 Braden Maillet
#include "PhotoMagic.hpp"
#include "FibLFSR.hpp"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main(int argc, char** argv) {
  string in = argv[1];
  string out = argv[2];
  string seed = argv[3];
  sf::Image image1;
  if (!image1.loadFromFile(in))  //  save original image for window1
    return -1;

  sf::Texture texture1;  //  texture for window 1
  texture1.loadFromImage(image1);
  sf::Sprite sprite1;
  sprite1.setTexture(texture1);

  PhotoMagic::FibLFSR fib(seed);  //  execution of encryption
  PhotoMagic::transform(image1, &fib);

  if (!image1.saveToFile(out))  //  save new image to out
    return -1;

  sf::Image image2;
  if (!image2.loadFromFile(out))  //  save out for window2
    return -1;

  sf::Vector2u size = image1.getSize();
  sf::RenderWindow window1(sf::VideoMode(size.x, size.y), in);
  sf::RenderWindow window2(sf::VideoMode(size.x, size.y), out);

  sf::Texture texture2;   //  texture for window 2 or output
  texture2.loadFromImage(image2);
  sf::Sprite sprite2;
  sprite2.setTexture(texture2);

  while (window1.isOpen() && window2.isOpen()) {
    sf::Event event;
    while (window1.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window1.close();
    }
    while (window2.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window2.close();
    }
      window1.clear(sf::Color::White);
      window1.draw(sprite1);
      window1.display();
      window2.clear(sf::Color::White);
      window2.draw(sprite2);
      window2.display();
  }
  return 0;
}
