// Copyright 2024 Braden Maillet
#include <fstream>
#include <iostream>
#include <string>
#include "Sokoban.hpp"
#include <SFML/Graphics.hpp>



#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

//  cantmove test
//  Boxwall

BOOST_AUTO_TEST_CASE(testplayerLoc) {
    std::ifstream myfile;
    SB::Sokoban a;
    sf::Vector2i tester(8, 5);
    sf::Vector2i testee;
    myfile.open("sokoban/level2.lvl");  //  player should be at 8 5
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testplayerLoc\n");
    }
    myfile >> a;
    testee = static_cast<sf::Vector2<int>>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testautowin) {
    std::ifstream myfile;
    myfile.open("sokoban/autowin.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testautowin\n");
    }
    SB::Sokoban a;
    myfile >> a;
    BOOST_REQUIRE_EQUAL(a.isWon(), true);
}
BOOST_AUTO_TEST_CASE(testautowin2) {
    std::ifstream myfile;
    myfile.open("sokoban/autowin2.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testautowin2\n");
    }
    SB::Sokoban a;
    myfile >> a;
    BOOST_REQUIRE_EQUAL(a.isWon(), true);
}
BOOST_AUTO_TEST_CASE(testpushleft) {
    std::ifstream myfile;
    sf::Vector2i tester(1, 2);
    sf::Vector2i testee;
    myfile.open("sokoban/pushleft.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testpushleft\n");
    }
    SB::Sokoban a;
    myfile >> a;
    //  player is at 3 3 and should stay there
    //  after moveplayer(SB::Left);
    a.movePlayer(SB::Direction::Left);
    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testpushright) {
    std::ifstream myfile;
    sf::Vector2i tester(3, 2);
    sf::Vector2i testee;
    myfile.open("sokoban/pushright.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testpushright\n");
    }
    SB::Sokoban a;
    myfile >> a;
    //  player is at 2 2 and should stay there
    //  after moveplayer(SB::Left);
    a.movePlayer(SB::Direction::Right);
    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testpushup) {
    std::ifstream myfile;
    sf::Vector2i tester(2, 1);
    sf::Vector2i testee;
    myfile.open("sokoban/pushup.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testpushup\n");
    }
    SB::Sokoban a;
    myfile >> a;
    //  std::cout << a;  //  DEBUG
    //  player is at 2 2 and should stay there
    //  after moveplayer(SB::Left);
    a.movePlayer(SB::Direction::Up);
    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testpushdown) {
    std::ifstream myfile;
    sf::Vector2i tester(2, 3);
    sf::Vector2i testee;
    myfile.open("sokoban/pushdown.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testpushdown\n");
    }
    SB::Sokoban a;
    myfile >> a;
    //  player is at 2 2 and should stay there
    //  after moveplayer(SB::Left);
    a.movePlayer(SB::Direction::Down);
    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testboxwal) {
    std::ifstream myfile;
    sf::Vector2i tester(7, 6);
    sf::Vector2i testee;
    myfile.open("sokoban/level1.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testboxwal\n");
    }
    SB::Sokoban a;
    myfile >> a;
    //  player is at 2 2 and should stay there
    //  after moveplayer(SB::Left);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Right);
    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testwal) {
    std::ifstream myfile;
    sf::Vector2i tester(1, 6);
    sf::Vector2i testee;
    myfile.open("sokoban/level1.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testwal\n");
    }
    SB::Sokoban a;
    myfile >> a;
    //  player is at 2 2 and should stay there
    //  after moveplayer(SB::Left);
    a.movePlayer(SB::Direction::Left);
    a.movePlayer(SB::Direction::Left);
    a.movePlayer(SB::Direction::Left);
    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testboxbox) {
    std::ifstream myfile;
    sf::Vector2i tester(8, 5);
    sf::Vector2i testee;
    myfile.open("sokoban/level2.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testboxbox\n");
    }
    SB::Sokoban a;
    myfile >> a;
    //  player is at 2 2 and should stay there
    //  after moveplayer(SB::Left);
    a.movePlayer(SB::Direction::Up);
    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testcanmove) {
    std::ifstream myfile;
    sf::Vector2i tester(1, 2);
    sf::Vector2i testee;
    myfile.open("sokoban/pushup.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testcanmove\n");
    }
    SB::Sokoban a;
    myfile >> a;

    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Down);
    a.movePlayer(SB::Direction::Left);
    a.movePlayer(SB::Direction::Left);
    a.movePlayer(SB::Direction::Up);

    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testmoveoffscreenLEFT) {
    std::ifstream myfile;
    sf::Vector2i tester(0, 2);
    sf::Vector2i testee;
    myfile.open("sokoban/pushup.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testmoveoffscreenLEFT\n");
    }
    SB::Sokoban a;
    myfile >> a;

    a.movePlayer(SB::Direction::Left);
    a.movePlayer(SB::Direction::Left);
    a.movePlayer(SB::Direction::Left);

    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testmoveoffscreenRIGHT) {
    std::ifstream myfile;
    sf::Vector2i tester(4, 2);
    sf::Vector2i testee;
    myfile.open("sokoban/pushup.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testmoveoffscreenRight\n");
    }
    SB::Sokoban a;
    myfile >> a;

    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Right);

    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testmoveoffscreenUP) {
    std::ifstream myfile;
    sf::Vector2i tester(3, 0);
    sf::Vector2i testee;
    myfile.open("sokoban/pushup.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testmoveoffscreenUP\n");
    }
    SB::Sokoban a;
    myfile >> a;

    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Up);
    a.movePlayer(SB::Direction::Up);
    a.movePlayer(SB::Direction::Up);

    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testmoveoffscreenDOWN) {
    std::ifstream myfile;
    sf::Vector2i tester(2, 4);
    sf::Vector2i testee;
    myfile.open("sokoban/pushup.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testmoveoffscreenDOWN\n");
    }
    SB::Sokoban a;
    myfile >> a;

    a.movePlayer(SB::Direction::Down);
    a.movePlayer(SB::Direction::Down);
    a.movePlayer(SB::Direction::Down);

    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testpushoffscreenLEFT) {
    std::ifstream myfile;
    sf::Vector2i tester(1, 1);
    sf::Vector2i testee;
    myfile.open("sokoban/pushup.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testpushoffscreenLEFT\n");
    }
    SB::Sokoban a;
    myfile >> a;

    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Up);
    a.movePlayer(SB::Direction::Left);
    a.movePlayer(SB::Direction::Left);
    a.movePlayer(SB::Direction::Left);

    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testpushoffscreenRIGHT) {
    std::ifstream myfile;
    sf::Vector2i tester(3, 1);
    sf::Vector2i testee;
    myfile.open("sokoban/pushup.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testpushoffscreenRIGHT\n");
    }
    SB::Sokoban a;
    myfile >> a;

    a.movePlayer(SB::Direction::Left);
    a.movePlayer(SB::Direction::Up);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Right);

    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testpushoffscreenUP) {
    std::ifstream myfile;
    sf::Vector2i tester(3, 1);
    sf::Vector2i testee;
    myfile.open("sokoban/pushup.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testpushoffscreenUP\n");
    }
    SB::Sokoban a;
    myfile >> a;

    a.movePlayer(SB::Direction::Left);
    a.movePlayer(SB::Direction::Up);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Down);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Up);
    a.movePlayer(SB::Direction::Up);

    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testpushoffscreenDOWN) {
    std::ifstream myfile;
    sf::Vector2i tester(4, 3);
    sf::Vector2i testee;
    myfile.open("sokoban/pushup.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testpushoffscreenDOWN\n");
    }
    SB::Sokoban a;
    myfile >> a;

    a.movePlayer(SB::Direction::Left);
    a.movePlayer(SB::Direction::Up);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Up);
    a.movePlayer(SB::Direction::Right);
    a.movePlayer(SB::Direction::Down);
    a.movePlayer(SB::Direction::Down);
    a.movePlayer(SB::Direction::Down);
    a.movePlayer(SB::Direction::Down);


    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
}
BOOST_AUTO_TEST_CASE(testWinLotsTargets) {
    std::ifstream myfile;
    sf::Vector2i tester(4, 3);
    sf::Vector2i testee;
    myfile.open("sokoban/lotstargets.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testWinLotsTargets\n");
    }
    SB::Sokoban a;
    myfile >> a;

    a.movePlayer(SB::Direction::Up);

    BOOST_REQUIRE_EQUAL(a.isWon(), true);
}
BOOST_AUTO_TEST_CASE(testWinlotsBoxes) {
    std::ifstream myfile;
    sf::Vector2i tester(4, 3);
    sf::Vector2i testee;
    myfile.open("sokoban/lotsBoxes.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testWinlotsBoxes\n");
    }
    SB::Sokoban a;
    myfile >> a;

    a.movePlayer(SB::Direction::Up);

    BOOST_REQUIRE_EQUAL(a.isWon(), true);
}
BOOST_AUTO_TEST_CASE(testWinMissingSymbol) {
    std::ifstream myfile;
    sf::Vector2i tester(2, 2);
    sf::Vector2i testee;
    myfile.open("sokoban/missingsymbol.lvl");
    if (!myfile.is_open()) {
        BOOST_FAIL("File failed to open in testWinMissingSymbol\n");
    }
    SB::Sokoban a;
    myfile >> a;

    testee = static_cast<sf::Vector2i>(a.playerLoc());
    BOOST_REQUIRE(testee.x == tester.x);
    BOOST_REQUIRE(testee.y == tester.y);
    BOOST_REQUIRE_EQUAL(a.isWon(), false);
}




