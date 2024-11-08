//  Copyright 2024 Braden Maillet
#include <memory>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <utility>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "CelestialBody.hpp"
#include "Universe.hpp"
// changes internal velocity for given time
void NB::Universe::step(double seconds) {
  const double GRAV = 0.000000000066742;
  //  Universe holds current time
  //  newTime - Curr time
  double changeInTime = seconds;
  double F;
  double distx = 0;
  double disty = 0;
  double distR = 0;
  double tempForcex = 0;  //  sum of net forces
  double tempForcey = 0;
  double tempAccelx = 0;
  double tempAccely = 0;
  double tempVelx = 0;
  double tempVely = 0;
  double tempPosx = 0;
  double tempPosy = 0;
  std::pair<double, double> totalF;
  //  calculate force for all bodies
  //  calculate acceleration for all bodies
  for (int i = 0; i < this->_numberOfPlanets; i++) {
      for (int j = 0; j < this->_numberOfPlanets; j++) {
        if (i != j) {
          //  calc distance between  CB's i and j;
          distx = (*this)[j].getxpos() - (*this)[i].getxpos();
          disty = (*this)[j].getypos() - (*this)[i].getypos();
          distR = sqrt((distx * distx) + (disty * disty));
          F = (GRAV * ((*this)[i].getmass()) *
                  ((*this)[j].getmass()))/ (distR * distR);
          tempForcex = (F * distx)/ distR;
          tempForcey = (F * disty)/ distR;
        } else if (i == j) {
          continue;
        }
        //  calculate net force for specific CB
        //  ie: sum individual forces or add Force just found
        totalF.first = totalF.first + tempForcex;
        totalF.second = totalF.second + tempForcey;
        tempForcex = 0;
        tempForcey = 0;
      }
      //  set net force for i and reset net force
      //  set accel for i using net force ax = forcex / mass
      tempAccelx = totalF.first/(*this)[i].getmass();
      tempAccely = totalF.second/(*this)[i].getmass();
      tempVelx = (*this)[i].getxvel() + (changeInTime * tempAccelx);
      tempVely = (*this)[i].getyvel() + (changeInTime * tempAccely);
      (*this)[i].setAccel(tempAccelx, tempAccely);
      (*this)[i].setForce(totalF.first, totalF.second);
      (*this)[i].setVelocity(tempVelx, tempVely);
      totalF.first = 0;
      totalF.second = 0;
      tempAccelx = 0;
      tempAccelx = 0;
      tempVelx = 0;
      tempVely = 0;
  }
  for (int i = 0; i < this->_numberOfPlanets; i++) {
    //  change pos/vel using old position and new velocity
    //  new velocity has been set already for all CB's
    tempPosx = (*this)[i].getxpos() + (changeInTime * (*this)[i].getxvel());
    tempPosy = (*this)[i].getypos() + (changeInTime * (*this)[i].getyvel());
    (*this)[i].setPos(tempPosx, tempPosy);
    tempPosx = 0;
    tempPosy = 0;
  }
  this->setTime(this->getTime() + seconds);  //  set new time
}

NB::Universe::Universe(std::string filename) {
  std::ifstream myfile;
  //  std::string file = "nbody-full/";
  //  std::string temp = filename;
  //  file.append(temp);
  myfile.open(filename);
  if (!myfile.is_open()) {
    std::cout << "failed to construct Universe due to faulty file: "
      <<  filename << std::endl;
      return;
  }
  myfile >> (*this);
  myfile.close();
}
//  checks in index is out of bounds but same as []
NB::CelestialBody& NB::Universe::getCelestialBody(int index) const {
    if (index > this->_numberOfPlanets) {
        std::cout <<
        "ERROR: index out of bounds in getter function, returning _p[0]"
        << std::endl;
        return *(this->_p[0]);
    }
    return *(this->_p[index]);
}
//  finds the celestial body with the highest
//  cartesian coordinate. ie furthest to edge.
double NB::Universe::getzoom(sf::RenderTarget& w) {
  double greatest = 0.0;
  sf::Vector2i v(w.getSize());
  double pixels = static_cast<double>(v.x);
  for (int i = 0; i < this->_numberOfPlanets; i++) {
      if ((_p[i])->findPos((_p[i])->getxpos()) >= greatest) {
         greatest = (_p[i])->findPos((_p[i])->getxpos());
      }
      if ((_p[i])->findPos((_p[i])->getypos()) >= greatest) {
         greatest = (_p[i])->findPos((_p[i])->getypos());
      }
  }
  greatest = abs(greatest);
  greatest = greatest + (pixels/2);
    std::cout << "pixels - greatest: "
    << greatest << std::endl;
  return greatest + 15;
}

void NB::Universe::draw(sf::RenderTarget& target,
    sf::RenderStates states) const {
  for (int i = 0; i < this->_numberOfPlanets; i++) {
    target.draw(*(this->_p[i]));
  }
}
namespace NB {
std::ostream& operator<<(std::ostream& out, Universe& a) {  //  NYT
  out << std::scientific;
  out << a._numberOfPlanets << std::endl <<
     a._universeRadius << std::endl;
  for (int i = 0; i < a._numberOfPlanets; i++) {
      out << *(a._p[i]);
  }
  return out;
}
std::istream& operator>>(std::istream& in, Universe& a) {  //  NYT
  NB::CelestialBody temp;
  in >> a._numberOfPlanets;
  in >> a._universeRadius;
  for (int i = 0; i < a._numberOfPlanets; i++) {
      a._p.push_back(std::make_shared<CelestialBody>());
      in >> *(a._p[i]);
      //  sets the pixel count of each body
      (*(a._p[i])).setPixel(a.getPixelCount());
      //  sets the radius of each body
      (*(a._p[i])).setRadius(a.getUniverseRadius());
  }
  return in;
}
}  //  namespace NB
