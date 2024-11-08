//  Copyright 2024 Braden Maillet
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Universe.hpp"

int main(int argc, char** argv) {
    const int windowsize = 700;
    double timeMax = atof(argv[1]);  //  time for physics
    double changeOfTime = atof(argv[2]);
    double time = 0;
    NB::Universe u;
    std::cin >> u;
    std::cout << u;
    std::cout << "size: " << windowsize << std::endl;
    sf::RenderWindow window(sf::VideoMode(700, 700), "Universe");
    sf::View view;
    //  sf::Vector2u temp = window.getSize();
    view.setCenter(windowsize / 2, windowsize / 2);
    //  view.zoom(u.getzoom(window));
    view.setSize(u.getzoom(window), u.getzoom(window));
    window.setView(view);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

            window.clear();
            if (time < timeMax) {
              window.draw(u);
              window.display();
              u.step(changeOfTime);  //  time + changeOfTime
              time = time + changeOfTime;
                  //  std::cout << "time " << time << std::endl;
                  //  std::cout << u;
                  //  std::cout << "vel x, y: " << u[0].velocity().x <<
                  //    " " << u[0].velocity().y << std::endl;
                  //  std::cout << "pos x, y: " << u[0].position().x <<
                  //    " " << u[0].position().y << std::endl;
            } else if (time >= timeMax) {
              std::cout << u;
                //  std::cout << "vel x, y: " << u[0].velocity().x <<
                //    " " << u[0].velocity().y << std::endl;
                //  std::cout << "pos x, y: " << u[0].position().x <<
                //    " " << u[0].position().y << std::endl;
              window.close();
            }
    }
    return 0;
}
