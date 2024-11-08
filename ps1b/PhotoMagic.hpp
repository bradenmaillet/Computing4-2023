// Copyright 2024 <Braden Maillet>
#pragma once
#include <algorithm>
#include "FibLFSR.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace PhotoMagic {
  void transform(sf::Image& image, FibLFSR* Fib);
}  //  namespace PhotoMagic
