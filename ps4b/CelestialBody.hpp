//  Copyright 2024 Braden Maillet
#pragma once
#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <iostream>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
namespace NB {
class CelestialBody : public sf::Drawable{
 public:
    CelestialBody() : _posSF(), _velSF(), _mass(), _pos(), _vel(),
      _force(), _accel(), _filename(), _pixelCount(), _radius() {}
    sf::Vector2f position() {return _posSF;}
    sf::Vector2f velocity() {return _velSF;}
    void setVelocity(double velx, double vely);
    void setPos(double posx, double posy);
    double getxpos() const {return _pos.first;}
    double getypos() const {return _pos.second;}
    double getxvel() const {return _vel.first;}
    double getyvel() const {return _vel.second;}
    double getmass() const {return _mass;}
    double mass() const {return _mass;}

    void setForce(double Fx, double Fy);
    void setAccel(double Ax, double Ay);
    void setPixel(int size) {_pixelCount = size;}
    void setRadius(double rad) {_radius = rad;}
    double findPos(double pos) const;

    friend std::ostream& operator<<(std::ostream& out, CelestialBody& a);
    friend std::istream& operator>>(std::istream& in, CelestialBody& a);

 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
    //  decided to store both a pair
    //  and a vector2f so i could have double
    //  and float values for return and calcs.
    //  _posSF has correct - and + y
    sf::Vector2f _posSF;
    sf::Vector2f _velSF;
    double _mass;
    std::pair<double, double> _pos;  //  (x,y)
    std::pair<double, double> _vel;  //  (x,y)
    std::pair<double, double> _force;
    std::pair<double, double> _accel;
    std::string _filename;
    sf::Texture _texture;
    sf::Sprite _sprite;
    int _pixelCount;
    double _radius;
};
}  //  namespace NB
