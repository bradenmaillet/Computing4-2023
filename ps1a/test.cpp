// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 1/8/2024

#include <iostream>
#include <string>
#include <sstream>

#include "FibLFSR.hpp"

using PhotoMagic::FibLFSR;

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testStepInstr) {
         FibLFSR one("1011011000110110");
         BOOST_REQUIRE_EQUAL(one.step(), 0);
         BOOST_REQUIRE_EQUAL(one.step(), 0);
         BOOST_REQUIRE_EQUAL(one.step(), 0);
         BOOST_REQUIRE_EQUAL(one.step(), 1);
         BOOST_REQUIRE_EQUAL(one.step(), 1);
         BOOST_REQUIRE_EQUAL(one.step(), 0);
         BOOST_REQUIRE_EQUAL(one.step(), 0);
         BOOST_REQUIRE_EQUAL(one.step(), 1);
}

BOOST_AUTO_TEST_CASE(testGenerateInstr) {
  FibLFSR one("1011011000110110");
  BOOST_REQUIRE_EQUAL(one.generate(9), 51);
}
BOOST_AUTO_TEST_CASE(teststepzero) {
  FibLFSR one("0000000000000000");
  BOOST_REQUIRE_EQUAL(one.step(), 0);
}
BOOST_AUTO_TEST_CASE(teststepone) {
  FibLFSR one("1111111111111111");
  BOOST_REQUIRE_EQUAL(one.step(), 0);
}
BOOST_AUTO_TEST_CASE(testoutpt) {
  FibLFSR one("1010101010101010");
  std::stringstream s;
  s << one;
  BOOST_REQUIRE_EQUAL(s.str(), "1010101010101010");
}
BOOST_AUTO_TEST_CASE(testshift) {
  FibLFSR one("1011010000000000");
  std::stringstream s;
  one.step();  //  0110100000000000
  one.step();  //  1101000000000001
  one.step();  //  1010000000000010
  one.step();  //  0100000000000100
  s << one;

  BOOST_REQUIRE_EQUAL(s.str(), "0100000000000100");
}
