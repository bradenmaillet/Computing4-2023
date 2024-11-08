//  Copyright 2024 Braden Maillet
#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "CelestialBody.hpp"

void NB::CelestialBody::setForce(double Fx, double Fy) {
  _force.first = Fx;
  _force.second = Fy;
}
void NB::CelestialBody::setAccel(double Ax, double Ay) {
  _accel.first = Ax;
  _accel.second = Ay;
}
void NB::CelestialBody::setVelocity(double velx, double vely) {
  _vel.first = velx;
  _vel.second = vely;
  _velSF.x = velx;
  _velSF.y = vely;
}
void NB::CelestialBody::setPos(double posx, double posy) {
  _pos.first = posx;
  _pos.second = posy;
  _posSF.x = posx;
  _posSF.y = posy;
}
void NB::CelestialBody::draw(sf::RenderTarget& target,
         sf::RenderStates states) const {
  sf::Sprite S = _sprite;
  double temp;
  sf::Vector2f vect(findPos(_pos.first) + (_pixelCount/2), 0);  //  x and y
    if ((findPos(_pos.second) + (_pixelCount/2)) == 350) {
        vect.y = 350;
    }
    if ((findPos(_pos.second) + (_pixelCount/2)) > 350) {
      temp = findPos(_pos.second);
      vect.y = (_pixelCount/2) - temp;
    }
    if ((findPos(_pos.second) + (_pixelCount/2)) < 350) {
      temp = findPos(_pos.second);
      vect.y = (_pixelCount/2) - temp;
    }
    //  std::cout << std::fixed << std::setprecision(2)
    //  << "Celestial body (x,y) and rad: " <<
    //  vect.x << " "
    //  << (findPos(_pos.second) + (_pixelCount/2)) << " " << vect.y
    //  << " " << std::scientific << this->_radius << " "
    //  << this->_filename << std::endl;  //  Debug

  S.setPosition(vect);
  S.setTexture(_texture);
  target.draw(S);
}
double NB::CelestialBody::findPos(double pos) const {
  return ((pos/_radius) * (_pixelCount/2));
}
namespace NB {
std::ostream& operator<<(std::ostream& out, CelestialBody& a) {
  out << a._pos.first << "  " << a._pos.second <<
      "  " << a._vel.first << "  " << a._vel.second <<
      "  " << a._mass << "  " << a._filename << std::endl;
  return out;
}
std::istream& operator>>(std::istream& in, CelestialBody& a) {
  std::string file = "nbody/";
  std::string temp;
  in >> a._pos.first;  //  _pos x
  a._posSF.x = a._pos.first;  //  SF
  in >> a._pos.second;  //  _pos y
  a._posSF.y = a._pos.second;  //  SF
  in >> a._vel.first;  //  _vel x
  a._velSF.x = a._vel.first;  //  SF
  in >> a._vel.second;  //  _vel y
  a._velSF.y = a._vel.second;  //  SF
  in >> a._mass;
  in >> a._filename;
  temp = a._filename;
  file.append(temp);
  if (!a._texture.loadFromFile(file)) {
    std::cout << "failed to load " << file << std::endl;
  }
  a._sprite.setTexture(a._texture);
  return in;
}
}  //  namespace NB
