// Copyright 2024 <Braden Maillet>
#include "PhotoMagic.hpp"
#include <iostream>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"

void PhotoMagic::transform(sf::Image& image, PhotoMagic::FibLFSR* Fib) {
  sf::Color p;
  sf::Vector2u size = image.getSize();
  PhotoMagic::FibLFSR shift = *Fib;
    for (unsigned int x = 0; x < size.x; x++) {
      for (unsigned int y = 0; y < size.y; y++) {
        p = image.getPixel(x, y);
        shift.generate(3);
        p.r = shift.getbi() ^ p.r;
        shift.generate(3);
        p.g = shift.getbi() ^ p.g;
        shift.generate(3);
        p.b = shift.getbi() ^ p.b;
        image.setPixel(x, y, p);
      }
    }
}
