//  Copyright 2024 Braden Maillet
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Sokoban.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

    SB::Sokoban::Sokoban() : _width(0), _height(0) {
        if (playerF.loadFromFile("sokoban/player_05.png") == false)
            std::cout << "failed to load playerF" << std::endl;
        if (playerB.loadFromFile("sokoban/player_08.png") == false)
            std::cout << "failed to load playerB" << std::endl;
        if (playerR.loadFromFile("sokoban/player_17.png") == false)
            std::cout << "failed to load playerR" << std::endl;
        if (playerL.loadFromFile("sokoban/player_20.png") == false)
            std::cout << "failed to load playerL" << std::endl;
        if (Wall.loadFromFile("sokoban/block_06.png") == false)
            std::cout << "failed to load Wall" << std::endl;
        if (Box.loadFromFile("sokoban/crate_03.png") == false)
            std::cout << "failed to load Box" << std::endl;
        if (Empty.loadFromFile("sokoban/ground_01.png") == false)
            std::cout << "failed to load Empty" << std::endl;
        if (Storage.loadFromFile("sokoban/ground_04.png") == false)
            std::cout << "failed to load Storage" << std::endl;
    }
    sf::Vector2i SB::Sokoban::playerLoc() const {
        sf::Vector2i vect;
        for (int x = 0; x < this->height(); x++) {
            for (int y = 0; y < this->width(); y++) {
                if (this->getvectcurr(x, y) == '@') {
                    vect.x = y;
                    vect.y = x;
                    return vect;
                }
            }
        }
        return vect;
    }
    sf::Vector2i SB::Sokoban::DirectionbasedLoc(enum SB::Direction D,
                        sf::Vector2i Loc, int count) {
        sf::Vector2i temp = Loc;
        temp.x++;  //  *****
        temp.y++;
        switch (D) {
            case SB::Up:
                temp.y = temp.y - count;
                break;
            case SB::Left:
                temp.x = temp.x - count;
                break;
            case SB::Down:
                temp.y = temp.y + count;
                break;
            case SB::Right:
                temp.x = temp.x + count;
                break;
            default:
                break;
        }
        return temp;
    }
    char SB::Sokoban::newtile_Pos0(sf::Vector2i Loc) {
        char temp = getvectOG(Loc.y, Loc.x);
        if (temp == 'A')  //  Box
            return '.';
        if (temp == '1')  //  box in storage
            return 'a';
        if (temp == '@')  //  player OG location
            return '.';

        return temp;
    }
    char SB::Sokoban::getvectcurr(int x, int y) const {
        if (x < 0 || y < 0)  //  check lower bounds
            return 'z';
        if (x >= _height || y >= _width)  //  check upper bounds
            return 'z';
        return this->currarena[x][y];
    }
    //  cases for check move that return false
    //  1. wall sqaure in direction D
    //  2. box sqaure followed by wall
    //  3. box sqaure followed by box square
    //  4. player reaches bounds of game
    //  5. box reaches bounds of game
    //  I'm finding more as i go along
    bool SB::Sokoban::checkmove(enum SB::Direction D, sf::Vector2i Loc) {
        sf::Vector2i hold = Loc;
        //  std::cout << "checkmove debug" <<
        //  hold.x << " " << hold.y << std::endl;
        switch (D) {
            case SB::Direction::Up:
                if (getvectcurr(hold.y - 1, hold.x) == '#')
                    return false;  // wall works

                if (getvectcurr(hold.y - 1, hold.x) == 'A' &&
                getvectcurr(hold.y - 2, hold.x) == '#')
                    return false;  //  box wall

                if (getvectcurr(hold.y - 1, hold.x) == 'A' &&
                getvectcurr(hold.y - 2, hold.x) == 'A')
                    return false;  //  box box

                if (getvectcurr(hold.y - 1, hold.x) == 'A' &&
                getvectcurr(hold.y - 2, hold.x) == '1')
                    return false;  //  box storage box

                if (hold.y == 0)
                    return false;  //  player reaches boundary

                if (getvectcurr(hold.y - 1, hold.x) == 'A' &&
                hold.y - 2 < 0)  //  box reaches boundary
                    return false;

                if (getvectcurr(hold.y - 1, hold.x) == '1' &&
                hold.y - 2 < 0)  //  box in storage reaches boundary
                    return false;

                if (getvectcurr(hold.y - 1, hold.x) == '1' &&
                getvectcurr(hold.y - 2, hold.x) == '#')
                    return false;  //  box wall second case

                if (getvectcurr(hold.y - 1, hold.x) == '1' &&
                getvectcurr(hold.y - 2, hold.x) == 'A')
                    return false;  //  box in storage and box case
                break;

            case SB::Direction::Left:
                if (getvectcurr(hold.y, hold.x - 1) == '#')
                    return false;

                if (getvectcurr(hold.y, hold.x - 1) == 'A' &&
                getvectcurr(hold.y, hold.x - 2) == '#')
                    return false;

                if (getvectcurr(hold.y, hold.x - 1) == 'A' &&
                getvectcurr(hold.y, hold.x - 2) == 'A')
                    return false;

                if (getvectcurr(hold.y, hold.x - 1) == 'A' &&
                getvectcurr(hold.y, hold.x - 2) == '1')
                    return false;

                if (hold.x - 1 < 0)
                    return false;

                if (getvectcurr(hold.y, hold.x - 1) == 'A' &&
                hold.x - 2 < 0)
                    return false;

                if (getvectcurr(hold.y, hold.x - 1) == '1' &&
                hold.x - 2 < 0)
                    return false;

                if (getvectcurr(hold.y, hold.x - 1) == '1' &&
                getvectcurr(hold.y, hold.x - 2) == '#')
                    return false;

                if (getvectcurr(hold.y, hold.x - 1) == '1' &&
                getvectcurr(hold.y, hold.x - 2) == 'A')
                    return false;
                break;

            case SB::Direction::Down:
                if (getvectcurr(hold.y + 1, hold.x) == '#')
                    return false;

                if (getvectcurr(hold.y + 1, hold.x) == 'A' &&
                getvectcurr(hold.y + 2, hold.x) == '#')
                    return false;

                if (getvectcurr(hold.y + 1, hold.x) == 'A' &&
                getvectcurr(hold.y + 2, hold.x) == 'A')
                    return false;

                if (getvectcurr(hold.y + 1, hold.x) == 'A' &&
                getvectcurr(hold.y + 2, hold.x) == '1')
                    return false;

                if (hold.y + 1 == this->height())
                    return false;

                if (getvectcurr(hold.y + 1, hold.x) == 'A' &&
                hold.y + 2 == this->height())
                    return false;

                if (getvectcurr(hold.y + 1, hold.x) == '1' &&
                hold.y + 2 > this->height())
                    return false;

                if (getvectcurr(hold.y + 1, hold.x) == '1' &&
                getvectcurr(hold.y + 2, hold.x) == '#')
                    return false;

                if (getvectcurr(hold.y, hold.x - 1) == '1' &&
                getvectcurr(hold.y, hold.x - 2) == 'A')
                    return false;
                break;

            case SB::Direction::Right:
                if (getvectcurr(hold.y, hold.x + 1) == '#')
                    return false;

                if (getvectcurr(hold.y, hold.x + 1) == 'A' &&
                getvectcurr(hold.y, hold.x + 2) == '#')
                    return false;

                if (getvectcurr(hold.y, hold.x + 1) == 'A' &&
                getvectcurr(hold.y, hold.x + 2) == 'A')
                    return false;

                if (getvectcurr(hold.y, hold.x + 1) == 'A' &&
                getvectcurr(hold.y, hold.x + 2) == '1')
                    return false;

                if (hold.x + 1 == this->width())  //  .x  &&  >  *****
                    return false;

                if (getvectcurr(hold.y, hold.x + 1) == 'A' &&
                hold.x + 2 == this->width())
                    return false;

                if (getvectcurr(hold.y, hold.x + 1) == '1' &&
                hold.x + 2 > this->width())
                    return false;

                if (getvectcurr(hold.y, hold.x + 1) == '1' &&
                getvectcurr(hold.y, hold.x + 2) == '#')
                    return false;

                if (getvectcurr(hold.y, hold.x - 1) == '1' &&
                getvectcurr(hold.y, hold.x - 2) == 'A')
                    return false;
                break;

            default:
                break;
        }
        //  std::cout << "returned true" << std::endl;
        return true;
    }
    void SB::Sokoban::movePlayer(enum SB::Direction D) {
        std::vector<char> temp1;
        sf::Vector2i Loc = this->playerLoc();
        //  change of tile cases
        //  1. current location change will always be
        //  '.' or 'a'
        //  2. change of one past is always '@'
        //  3. change of 2 past: only be effected if pushing box
        //  'A' if currently '.'
        //  '1' if currently 'a'

        //  can seperate these into 2 broader statements
        //  1. is a box being pushed
        //  2. is a box not being pushed
        switch (D) {
            case SB::Up:
                if (checkmove(SB::Up, Loc)) {
                      //  is box being pushed
                    if (getvectcurr(Loc.y - 1, Loc.x) == 'A' &&
                    getvectcurr(Loc.y - 2, Loc.x) != 'a') {
                        setvectcurr('A', Loc.y - 2, Loc.x);  //  pos + 2
                    }
                      //  is box being pushed into storage
                    if (getvectcurr(Loc.y - 1, Loc.x) == 'A' &&
                    getvectcurr(Loc.y - 2, Loc.x) == 'a') {
                        setvectcurr('1', Loc.y - 2, Loc.x);  //  pos + 2
                    }
                      // is box in storage being pushed
                    if (getvectcurr(Loc.y - 1, Loc.x) == '1' &&
                    getvectcurr(Loc.y - 2, Loc.x) == '.') {
                        setvectcurr('A', Loc.y - 2, Loc.x);
                    }
                    setvectcurr('@', Loc.y - 1, Loc.x);  //  pos + 1
                    setvectcurr(newtile_Pos0(Loc), Loc.y, Loc.x);  //  pos
                }
                break;
            case SB::Left:
                if (checkmove(SB::Left, Loc)) {
                    if (getvectcurr(Loc.y, Loc.x - 1) == 'A' &&
                    getvectcurr(Loc.y, Loc.x - 2) != 'a') {
                        setvectcurr('A', Loc.y, Loc.x - 2);
                    }
                      //  is box being pushed into storage
                    if (getvectcurr(Loc.y, Loc.x - 1) == 'A' &&
                    getvectcurr(Loc.y, Loc.x - 2) == 'a') {
                        setvectcurr('1', Loc.y, Loc.x - 2);  //  pos + 2
                    }
                    if (getvectcurr(Loc.y, Loc.x - 1) == '1' &&
                    getvectcurr(Loc.y, Loc.x - 2) == '.') {
                        setvectcurr('A', Loc.y, Loc.x - 2);
                    }
                    setvectcurr('@', Loc.y, Loc.x - 1);
                    setvectcurr(newtile_Pos0(Loc), Loc.y, Loc.x);  /////
                }
                break;
            case SB::Down:
                if (checkmove(SB::Down, Loc)) {
                    if (getvectcurr(Loc.y + 1, Loc.x) == 'A' &&
                    getvectcurr(Loc.y + 2, Loc.x) != 'a') {
                        setvectcurr('A', Loc.y + 2, Loc.x);
                    }
                    if (getvectcurr(Loc.y + 1, Loc.x) == 'A' &&
                    getvectcurr(Loc.y + 2, Loc.x) == 'a') {
                        setvectcurr('1', Loc.y + 2, Loc.x);
                    }
                    if (getvectcurr(Loc.y + 1, Loc.x) == '1' &&
                    getvectcurr(Loc.y + 2, Loc.x) == '.') {
                        setvectcurr('A', Loc.y + 2, Loc.x);
                    }
                    setvectcurr('@', Loc.y + 1, Loc.x);
                    setvectcurr(newtile_Pos0(Loc), Loc.y, Loc.x);
                }
                break;
            case SB::Right:
                if (checkmove(SB::Right, Loc)) {
                    if (getvectcurr(Loc.y, Loc.x + 1) == 'A' &&
                    getvectcurr(Loc.y, Loc.x + 2) != 'a') {
                        setvectcurr('A', Loc.y, Loc.x + 2);
                    }
                    if (getvectcurr(Loc.y, Loc.x + 1) == 'A' &&
                    getvectcurr(Loc.y, Loc.x + 2) == 'a') {
                        setvectcurr('1', Loc.y, Loc.x + 2);
                    }
                    if (getvectcurr(Loc.y, Loc.x + 1) == '1' &&
                    getvectcurr(Loc.y, Loc.x + 2) == '.') {
                        setvectcurr('A', Loc.y, Loc.x + 2);
                    }
                    setvectcurr('@', Loc.y, Loc.x + 1);
                    setvectcurr(newtile_Pos0(Loc), Loc.y, Loc.x);
                }
                break;
            default:
                break;
        }
        //  std::cout << *this << std::endl <<
        //  "DEBUG MOVEPLAYER" << std::endl;  //  DEBUG
    }
    bool SB::Sokoban::isWon() {
        //  NYI
        //  will be for part b
        //  use algorithm c++ library and lambda
        //  expression as required by assignment
        int countStor = 0;
        int countBox = 0;
        int countOne = 0;
        for (const auto& row : this->currarena) {  //  counts elements of game
            countStor += std::count_if(row.begin(), row.end(), [](char a){
            return (a == '1' || a == 'a') ? true : false;
            });
            countBox += std::count_if(row.begin(), row.end(), [](char a){
            return (a == '1' || a == 'A') ? true : false;
            });
            countOne += std::count_if(row.begin(), row.end(), [](char a){
            return a == '1' ? true : false;
            });
        }
        //  checks if storage is full or if boxes are all stored
        if (countOne == countStor || countOne == countBox) {
            return true;
        }
        //  std::cout << "DEBUG: " << countStor << " " <<
            //  countBox << " " << countOne << std::endl;  //  DEBUG
        return false;
    }
namespace SB {
    std::ostream& operator<<(std::ostream& out, SB::Sokoban& a) {
        out << a.height() << " " << a.width() << std::endl;
        for (int x = 0; x < a.height(); x++) {
            for (int y = 0; y < a.width(); y++) {
                out << a.getvectcurr(x, y);
            }
            out << std::endl;
        }
        return out;
    }
    std::ifstream& operator>>(std::ifstream& in, SB::Sokoban& a) {  // NYT
        std::vector<char> temp;
        char tempchar;
        int tempint;
        in >> tempint;           //  set height and width
        a.setheight(tempint);
        in >> tempint;
        a.setwidth(tempint);
        for (int i = 0; i < a.height(); i++) {
            for (int j = 0; j < a.width(); j++) {
                if (!in.eof()) {
                in >> tempchar;
                temp.push_back(tempchar);
                }
            }
            a.setvectOG(temp);
            a.setvectcurr(temp);
            temp.clear();
        }
        return in;
    }
}  //  namespace SB
    void SB::Sokoban::draw(sf::RenderTarget& target,
     sf::RenderStates states) const {
        //  size of each square is 64 * 64
        sf::Vector2f vect(0.0f, 0.0f);
        sf::Sprite S;
        for (int i = 0; i < this->height(); i++) {   //  draw walls and floor
            for (int j = 0; j < this->width(); j++) {
                S.setPosition(vect);
                if (this->getvectcurr(i, j) == '#') {
                    S.setTexture(Wall);
                    target.draw(S);
                } else if (this->getvectcurr(i, j) == '.') {
                    S.setTexture(Empty);
                    target.draw(S);
                } else if (this->getvectcurr(i, j) == 'a') {
                    S.setTexture(Empty);
                    target.draw(S);
                    S.setTexture(Storage);
                    target.draw(S);
                } else if (this->getvectcurr(i, j) == 'A') {
                    S.setTexture(Empty);
                    target.draw(S);
                    S.setTexture(Box);
                    target.draw(S);
                } else if (this->getvectcurr(i, j) == '@') {
                    S.setTexture(Empty);
                    target.draw(S);
                    S.setTexture(playerF);
                    target.draw(S);
                } else if (this->getvectcurr(i, j) == '1') {
                    S.setTexture(Empty);
                    target.draw(S);
                    S.setTexture(Storage);
                    target.draw(S);
                    S.setTexture(Box);
                    target.draw(S);
                }
                vect.x = vect.x + 64;
            }
            vect.x = 0;
            vect.y = vect.y + 64;
        }
    }
    void SB::Sokoban::reset() {
        this->currarena = this->OGarena;
    }
