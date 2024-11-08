//  Copyright 2024 Braden Maillet
#include <iostream>
#include <fstream>
#include "Sokoban.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char** argv) {
    sf::Vector2i temp;
    std::ifstream myfile;
    sf::Text text;
    myfile.open(argv[1]);
    if (!myfile.is_open()) {
        std::cout << "File failed to open" << std::endl;
        return -1;
    }
    SB::Sokoban a;
    myfile >> a;
    myfile.close();
    //  std::cout << a;  //  DEBUG

    //  font for "you win" text
    //  Font Designed by Isa Ozler
    //  Open for use through Google Fonts
    sf::Font font;
    if (!font.loadFromFile("KodeMono-Regular.ttf")) {
        std::cout << "Text failed to load" << std::endl;
        return -1;
    }
    text.setFont(font);
    text.setString("You Win! 'r' to continue.");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Blue);
    //  width * 64 / 2 ; height * 64 / 2
    text.setPosition(a.width() * 32, a.height() * 32);

    //  make window and set size
    sf::RenderWindow window(sf::VideoMode(64 * a.width()
                            , 64 * a.height()), "sokoban");
    window.draw(a);
    //  temp = a.playerLoc();  //  DEBug
    //  std::cout << temp.x << " " << temp.y << std::endl;  //  DEBUG

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
              //  Redraw everytime key is pressed
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                a.movePlayer(SB::Direction::Up);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                a.movePlayer(SB::Direction::Left);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                a.movePlayer(SB::Direction::Down);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                a.movePlayer(SB::Direction::Right);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
                a.reset();
            }
            //  test if game is won
            if (a.isWon()) {
                window.clear();
                window.draw(a);
                window.draw(text);
                window.display();
                //  Reset game
                while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
                    //  loop holds position in game
                    //  at this point the player will
                    //  1. click R and the game will reset
                    //  or close the window and quit
                }
                a.reset();
            }
            window.clear();
            window.draw(a);
            window.display();
    }

    return 0;
}
