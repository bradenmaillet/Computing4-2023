//  Copyright 2024 Braden Maillet
#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "CelestialBody.hpp"

namespace NB {
class Universe : public sf::Drawable{
 public:
    Universe() : _currTime(0), _numberOfPlanets(), _universeRadius() {}
    explicit Universe(std::string filename);
    CelestialBody& getCelestialBody(int index) const;
    int getNumberOfPlanets() const {return _numberOfPlanets;}
    // numplanets is same as getnumberofplanets
    int numPlanets() const {return _numberOfPlanets;}
    double getUniverseRadius() const {return _universeRadius;}
    //  radius is same as getUniverseRadius
    double radius() const {return _universeRadius;}
    int getPixelCount() const {return _pixelCount;}
    double getzoom(sf::RenderTarget& target);
    double metersPerPixel() const {return _universeRadius/_pixelCount;}
    CelestialBody& operator[](int index) {return *(_p[index]);}
    void step(double seconds);
    void setTime(double time) {_currTime = time;}
    double getTime() {return _currTime;}

    friend std::ostream& operator<<(std::ostream& out, Universe& a);
    friend std::istream& operator>>(std::istream& in, Universe& a);

 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
    const int _pixelCount = 700;
    double _currTime;
    int _numberOfPlanets;
    double _universeRadius;
    std::vector<std::shared_ptr<CelestialBody>> _p;
};
}  //  namespace NB
