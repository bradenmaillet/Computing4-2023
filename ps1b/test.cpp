// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 1/8/2024

#include <iostream>
#include <string>

#include "PhotoMagic.hpp"
#include "FibLFSR.hpp"

using std::endl;
using std::string;
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
BOOST_AUTO_TEST_CASE(testClassSize) {
  FibLFSR one("1011011000110110");
  BOOST_REQUIRE_EQUAL(one.getsize(), 16);
}
BOOST_AUTO_TEST_CASE(teststepzero) {
  FibLFSR one("0000000000000000");
  BOOST_REQUIRE_EQUAL(one.step(), 0);
}
BOOST_AUTO_TEST_CASE(teststepone) {
  FibLFSR one("1111111111111111");
  BOOST_REQUIRE_EQUAL(one.step(), 0);
}
BOOST_AUTO_TEST_CASE(testseednochange) {
  FibLFSR one("1011011000110110");
  one.generate(5);
  BOOST_REQUIRE_EQUAL(one.getseed(), "1011011000110110");
}
BOOST_AUTO_TEST_CASE(testNE) {
  string stri = "1011011000110110";
  FibLFSR one(stri);
  BOOST_REQUIRE_NE(one.getbi(), one.step());
}
BOOST_AUTO_TEST_CASE(testout) {
  FibLFSR one("101101100011011");
  BOOST_REQUIRE_NO_THROW(cout << one << endl);
}
