//  Copyright 2024 Braden Maillet
#include <cmath>
#include <iostream>
#include <string>
#include "PTree.hpp"
#include <SFML/Graphics.hpp>


int main(int argc, char** argv) {
    //  length of side for base square
    double L = static_cast<double>(std::stoi(argv[1]));
    int N = std::stoi(argv[2]);  //  depth of the recursion
    sf::RenderWindow window(sf::VideoMode((L * 6), L * 4),
        "Pythagoras Tree");
    myDraw D(L, N);
    D.rdraw(D, window);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
    return 0;
}
