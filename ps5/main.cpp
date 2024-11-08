//  Copyright 2024 Braden Maillet
#include <vector>
#include <string>
#include <iostream>
#include <SFML/System.hpp>
#include "EDistance.hpp"

int main(int argc, char* argv[]) {
  sf::Clock clock;
  std::string input1, input2;
  std::cin >> input1;
  std::cin >> input2;
  EDistance E(input1, input2);
  int x = E.optDistance();
  std::cout << "Edit distance = " <<
    x << std::endl;
  std::cout << E.alignment();
  //  std::cout << E << std::endl;
  sf::Time t = clock.getElapsedTime();
  std::cout << "Execution time is " <<
     t.asSeconds() << " seconds" << std::endl;
  return 0;
}
