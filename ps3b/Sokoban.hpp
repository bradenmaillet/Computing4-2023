//  Copyright 2024 Braden Maillet
#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

namespace SB {
enum Direction {Up, Down, Left, Right};
class Sokoban : public sf::Drawable{
 public:
    Sokoban();
    int width() const { return _width; }
    void setwidth(int width) { _width = width; }
    int height() const { return _height; }
    void setheight(int height) { _height = height; }
    char getvectOG(int x, int y) const { return OGarena[x][y]; }
    void setvectOG(const std::vector<char>& v) { OGarena.push_back(v); }
    char getvectcurr(int x, int y) const;
    void setvectcurr(const std::vector<char>& v) { currarena.push_back(v); }
    void setvectcurr(char c, int h, int l) { currarena[h][l] = c; }
    sf::Vector2i playerLoc() const;
    sf::Vector2i DirectionbasedLoc(enum Direction D,
         sf::Vector2i Loc, int count);
    bool checkmove(enum Direction D, sf::Vector2i Loc);
    char newtile_Pos0(sf::Vector2i Loc);
    void movePlayer(enum Direction D);
    bool isWon();
    void reset();

    friend std::ostream& operator<<(std::ostream& out, SB::Sokoban& a);
    friend std::ifstream& operator>>(std::ifstream& in, SB::Sokoban& a);

 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
    int _width;
    int _height;
    std::vector<std::vector<char>> OGarena;
    std::vector<std::vector<char>> currarena;
    sf::Texture playerF;
    sf::Texture playerB;
    sf::Texture playerR;
    sf::Texture playerL;
    sf::Texture Wall;
    sf::Texture Box;
    sf::Texture Empty;
    sf::Texture Storage;
};
}  //  namespace SB
