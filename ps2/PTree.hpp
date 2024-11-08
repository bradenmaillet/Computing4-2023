//  Copyright 2024 Braden Maillet
#pragma once
#include <SFML/Graphics.hpp>

class myDraw : public sf::RectangleShape {
 public:
      myDraw() : sf::RectangleShape() {}
      myDraw(double slength, int reps) : sf::RectangleShape(
        sf::Vector2f(slength, slength)),
        _slength(slength), _reps(reps) {}
      double getlength() const { return this->_slength;}
      int getreps() const { return this->_reps;}
      void setlength(double length) {this->_slength = length;}
      void setreps(int reps) {this->_reps = reps;}
      void rdraw(myDraw& D, sf::RenderWindow& win);
      void rdrawhelp(myDraw&, sf::RenderWindow& win);
 private:
    double _slength;
    int _reps;
};
