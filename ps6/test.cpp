//  Copyright 2024 Braden Maillet
#include <iostream>
#include <fstream>
#include "RandWriter.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testlength) {
  RandWriter r("12345", 2);
  std::string test = r.generate("12", 6);
  BOOST_REQUIRE(test.size() == 6);
}
BOOST_AUTO_TEST_CASE(testexceptionfreq) {
  RandWriter r("12345", 2);
  BOOST_REQUIRE_THROW(r.freq("123"), std::logic_error);
}
BOOST_AUTO_TEST_CASE(testnoexceptionfreq) {
  RandWriter r("12345", 2);
  BOOST_REQUIRE_NO_THROW(r.freq("12"));
}
BOOST_AUTO_TEST_CASE(testexceptionfreqc) {
  RandWriter r("12345", 2);
  BOOST_REQUIRE_THROW(r.freq("123", 1), std::logic_error);
}
BOOST_AUTO_TEST_CASE(testnoexceptionfreqc1) {
  RandWriter r("12345", 2);
  BOOST_REQUIRE_NO_THROW(r.freq("12", 1));
}
BOOST_AUTO_TEST_CASE(testnoexceptionfreqc2) {
  RandWriter r("12345", 2);
  BOOST_REQUIRE_NO_THROW(r.freq("51", 1));
}
BOOST_AUTO_TEST_CASE(testordk) {
  RandWriter r("12345", 2);
  BOOST_REQUIRE(r.orderK() == 2);
}
BOOST_AUTO_TEST_CASE(testkrandexcept1) {
  RandWriter r("12345", 2);
  BOOST_REQUIRE_THROW(r.kRand("123"), std::logic_error);
}
BOOST_AUTO_TEST_CASE(testkrandexcept2) {
  RandWriter r("12345", 2);
  BOOST_REQUIRE_THROW(r.kRand("14"), std::logic_error);
}
BOOST_AUTO_TEST_CASE(testkrandnoexcept) {
  RandWriter r("12345", 2);
  BOOST_REQUIRE_NO_THROW(r.kRand("51"));
}
BOOST_AUTO_TEST_CASE(teststart1) {
  RandWriter r("12345", 2);
  std::string test = r.generate("12", 6);
  BOOST_REQUIRE(test.at(0) == '1');
}

