//  Copyright 2024 Braden Maillet
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Universe.hpp"
#include "CelestialBody.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testgetbodies) {
  NB::Universe u;
  std::stringstream s;
    s << "3\n" << "6.0E8\n" <<
    " 5.000000e+08  0.000000e+00  0.000000e+00" <<
      "-2.482233e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08  4.330127e+08  2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08 -4.330127e+08 -2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n";
  s >> u;
  BOOST_REQUIRE(u.numPlanets() == 3);
}
BOOST_AUTO_TEST_CASE(testgetradius) {
  NB::Universe u;
  std::stringstream s;
    s << "3\n" << "6.0E8\n" <<
    " 5.000000e+08  0.000000e+00  0.000000e+00" <<
      "-2.482233e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08  4.330127e+08  2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08 -4.330127e+08 -2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n";
  s >> u;
  //  std::cout <<  "testgetradius " << u.radius() << std::endl;
  BOOST_REQUIRE(u.radius() == 6.0E8);
}
BOOST_AUTO_TEST_CASE(testCBodyPos) {
  NB::Universe u;
  std::stringstream s;
    s << "3\n" << "6.0E8\n" <<
    " 5.000000e+08  0.000000e+00  0.000000e+00" <<
      "-2.482233e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08  4.330127e+08  2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08 -4.330127e+08 -2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n";
  s >> u;
  sf::Vector2f c(u[0].position());
  //  std::cout << "testCBodyPos debugging: " << c.x << " " << c.y << std::endl;
  BOOST_REQUIRE_CLOSE(c.x, static_cast<float>(5.000000e+08), .01);
  BOOST_REQUIRE_CLOSE(c.y, static_cast<float>(0.000000e+00), .01);
}
BOOST_AUTO_TEST_CASE(testCBodyvel) {
  NB::Universe u;
  std::stringstream s;
    s << "3\n" << "6.0E8\n" <<
    " 5.000000e+08  0.000000e+00  0.000000e+00" <<
      "-2.482233e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08  4.330127e+08  2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08 -4.330127e+08 -2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n";
  s >> u;
  //  std::cout << "testCBodyvel debugging: " << u[0] << " "  << std::endl;
  sf::Vector2f c(u[0].velocity());
  //  std::cout << "testCBodyvel debugging: " << c.x << " " << c.y << std::endl;
  BOOST_REQUIRE_CLOSE(c.x, static_cast<float>(0.000000e+00), .01);
  BOOST_REQUIRE_CLOSE(c.y, static_cast<float>(-2.482233e+02), .01);
}
BOOST_AUTO_TEST_CASE(testCBodymass) {
  NB::Universe u;
  std::stringstream s;
    s << "3\n" << "6.0E8\n" <<
    " 5.000000e+08  0.000000e+00  0.000000e+00" <<
      "-2.482233e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08  4.330127e+08  2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08 -4.330127e+08 -2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n";
  s >> u;
  //  std::cout << "testCBodyvel debugging: "
  //  << u[0]->mass() << " "  << std::endl;
  BOOST_REQUIRE_CLOSE(u[0].mass(), 8.00e+23, .01);
}
BOOST_AUTO_TEST_CASE(testUout) {
  NB::Universe u;
  std::stringstream s;
    s << "3\n" << "6.0E8\n" <<
    " 5.000000e+08  0.000000e+00  0.000000e+00" <<
      "-2.482233e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08  4.330127e+08  2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08 -4.330127e+08 -2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n";
  s >> u;
  int bodycount;
  double radius;
  double posx;
  double posy;
  double velx;
  double vely;
  double mass;
  std::string str;
  s << u;
  s >> bodycount;
  s >> radius;
  s >> posx;
  s >> posy;
  s >> velx;
  s >> vely;
  s >> mass;
  s >> str;

  BOOST_REQUIRE(bodycount == 3);
  BOOST_REQUIRE_CLOSE(radius, 6.0E8, .01);
  BOOST_REQUIRE_CLOSE(posx, 5.000000e+08, .01);
  BOOST_REQUIRE_CLOSE(posy, 0.000000e+00, .01);
  BOOST_REQUIRE_CLOSE(velx, 0.000000e+00, .01);
  BOOST_REQUIRE_CLOSE(vely, -2.482233e+02, .01);
  BOOST_REQUIRE_CLOSE(mass, 8.00e+23, .01);
  BOOST_REQUIRE(str == "earth.gif");
}
BOOST_AUTO_TEST_CASE(testCBout) {
  NB::Universe u;
  std::stringstream s;
    s << "3\n" << "6.0E8\n" <<
    " 5.000000e+08  0.000000e+00  0.000000e+00" <<
      "-2.482233e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08  4.330127e+08  2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08 -4.330127e+08 -2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n";
  s >> u;
  NB::CelestialBody c = u[0];
  double posx;
  double posy;
  double velx;
  double vely;
  double mass;
  std::string str;
  s << c;
  s >> posx;
  s >> posy;
  s >> velx;
  s >> vely;
  s >> mass;
  s >> str;

  BOOST_REQUIRE_CLOSE(posx, 5.000000e+08, .01);
  BOOST_REQUIRE_CLOSE(posy, 0.000000e+00, .01);
  BOOST_REQUIRE_CLOSE(velx, 0.000000e+00, .01);
  BOOST_REQUIRE_CLOSE(vely, -2.482233e+02, .01);
  BOOST_REQUIRE_CLOSE(mass, 8.00e+23, .01);
  BOOST_REQUIRE(str == "earth.gif");
}
BOOST_AUTO_TEST_CASE(teststepVEL) {
  NB::Universe u;
  std::stringstream s;
  sf::Vector2f vel;
    s << "3\n" << "6.0E8\n" <<
    " 5.000000e+08  0.000000e+00  0.000000e+00" <<
      "-2.482233e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08  4.330127e+08  2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08 -4.330127e+08 -2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n";
  s >> u;
  u.step(25000.0);
  vel = u[0].velocity();
  BOOST_REQUIRE_CLOSE(vel.x, -3.082681e+00, .1);
  BOOST_REQUIRE_CLOSE(vel.y, -2.482233e+02, .1);
}
BOOST_AUTO_TEST_CASE(teststepPOS) {
  NB::Universe u;
  std::stringstream s;
  sf::Vector2f pos;
    s << "3\n" << "6.0E8\n" <<
    " 5.000000e+08  0.000000e+00  0.000000e+00" <<
      "-2.482233e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08  4.330127e+08  2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n" <<
    "-2.500000e+08 -4.330127e+08 -2.149677e+02" <<
      "1.241117e+02 8.00e+23 earth.gif\n";
  s >> u;
  u.step(25000.0);
  pos = u[0].position();

  BOOST_REQUIRE_CLOSE(pos.x, 4.999229e+08, .1);
  BOOST_REQUIRE_CLOSE(pos.y, -6.205582e+06, .1);
}
BOOST_AUTO_TEST_CASE(testprec5) {
  NB::Universe u("nbody-full/uniform3.txt");
  sf::Vector2f vel;
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  //  std::cout << u << std::endl;
  vel = u[0].velocity();
  BOOST_REQUIRE_CLOSE(vel.x, -1.541104e+01, .1);
  BOOST_REQUIRE_CLOSE(vel.y, -2.478405e+02, .1);
}
BOOST_AUTO_TEST_CASE(testprec10) {
  NB::Universe u("nbody-full/uniform3.txt");
  sf::Vector2f vel;
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  vel = u[0].velocity();
  //  std::cout << u << std::endl;

  BOOST_REQUIRE_CLOSE(vel.x, -3.078049e+01, .1);
  BOOST_REQUIRE_CLOSE(vel.y, -2.465010e+02, .1);
}
BOOST_AUTO_TEST_CASE(testgrav) {
  NB::Universe u("nbody-full/uniform3.txt");
  sf::Vector2f vel;
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  u.step(25000.0);
  vel = u[0].velocity();
  //  std::cout << u << std::endl;
  if (vel.x > 0) {
    BOOST_TEST_FAIL("Gravity inverted");
  }
}
BOOST_AUTO_TEST_CASE(testdelta) {
  NB::Universe u("nbody-full/uniform3.txt");
  sf::Vector2f vel1;
  sf::Vector2f vel2;
  u.step(25000.0);
  vel1 = u[0].velocity();
  u.step(25000.0);
  vel2 = u[0].velocity();

  BOOST_REQUIRE_CLOSE(vel1.x, -3.082681e+00, .1);
  BOOST_REQUIRE_CLOSE(vel1.y, -2.482233e+02, .1);
  BOOST_REQUIRE_CLOSE(vel2.x, -6.165600e+00, .1);
  BOOST_REQUIRE_CLOSE(vel2.y, -2.481850e+02, .1);
}
BOOST_AUTO_TEST_CASE(testposchange) {
  NB::Universe u("nbody-full/uniform3.txt");
  sf::Vector2f pos1;
  sf::Vector2f pos2;
  u.step(25000.0);
  pos1 = u[0].position();
  u.step(25000.0);
  pos2 = u[0].position();

  BOOST_REQUIRE_CLOSE(pos1.x, 4.999229e+08, .1);
  BOOST_REQUIRE_CLOSE(pos1.y, -6.205582e+06, .1);
  BOOST_REQUIRE_CLOSE(pos2.x, 4.997688e+08, .1);
  BOOST_REQUIRE_CLOSE(pos2.y, -1.241021e+07, .1);
}
