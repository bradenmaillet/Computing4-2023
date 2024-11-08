//  Copyright 2024 Braden Maillet
#include <iostream>
#include <fstream>
#include "EDistance.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testcost1) {
  EDistance E("12345", "34567");

  BOOST_CHECK_EQUAL(E.optDistance(), 5);
}
BOOST_AUTO_TEST_CASE(testcost2) {
  EDistance E("atattat", "tattata");

  BOOST_CHECK_EQUAL(E.optDistance(), 4);
}
BOOST_AUTO_TEST_CASE(testcost3) {
  EDistance E("atattat", "tattata");

  BOOST_CHECK_EQUAL(E.optDistance(), 4);
}
BOOST_AUTO_TEST_CASE(testcost4) {
  EDistance E("AACAGTTACC", "TAAGGTCA");

  BOOST_CHECK_EQUAL(E.optDistance(), 7);
}
BOOST_AUTO_TEST_CASE(testendgaps) {
  EDistance E("atattat", "tattata");
  std::string test = "a - 2\nt t 0\na a 0\nt t 0\n"
                      "t t 0\na a 0\nt t 0\n- a 2\n";
  E.optDistance();
  BOOST_CHECK_EQUAL(E.alignment(), test);
}
BOOST_AUTO_TEST_CASE(testmin3a) {
  EDistance E("atattat", "tattata");
  BOOST_CHECK_EQUAL(E.min3(1, 2, 3), 1);
}
BOOST_AUTO_TEST_CASE(testmin3b) {
  EDistance E("atattat", "tattata");
  BOOST_CHECK_EQUAL(E.min3(2, 1, 3), 1);
}
BOOST_AUTO_TEST_CASE(testmin3c) {
  EDistance E("atattat", "tattata");
  BOOST_CHECK_EQUAL(E.min3(3, 2, 1), 1);
}
BOOST_AUTO_TEST_CASE(testpenaltymis) {
  EDistance E("atattat", "tattata");
  BOOST_CHECK_EQUAL(E.penalty('a', 'b'), 1);
}
BOOST_AUTO_TEST_CASE(testpenaltymatch) {
  EDistance E("atattat", "tattata");
  BOOST_CHECK_EQUAL(E.penalty('a', 'a'), 0);
}
BOOST_AUTO_TEST_CASE(testswp) {
  EDistance E("atattat", "tattata");
  std::string test = "- a 2\n"
                      "t t 0\n"
                      "a a 0\n"
                      "t t 0\n"
                      "t t 0\n"
                      "a a 0\n"
                      "t t 0\n"
                      "a - 2\n";
  E.optDistance();
  BOOST_CHECK_NE(E.alignment(), test);
}
