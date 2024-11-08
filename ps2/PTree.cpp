//  Copyright 2024 Braden Maillet
#include "PTree.hpp"
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

//  (0,0) is always top left on square even with origin change
void myDraw::rdraw(myDraw& D, sf::RenderWindow& win) {
    sf::Vector2f size(D.getlength(), D.getlength());
    sf::Vector2f temp;
    const float Csize = sin(M_PI/4);
    if (D.getreps() == 0)    //   null case
        return;
    D.setSize(size);        //  base square or first sqaure
    D.setPosition(((6 * D.getlength())/2) - (D.getlength()/2),
      ((4 * D.getlength())/2) + D.getlength());
    D.setFillColor(sf::Color::Red);
    sf::Transform trans = D.getTransform();
    myDraw DL = D;
    myDraw DR = D;
    win.draw(D);

    DL.setSize(size * Csize);
    DL.setOrigin(0, DL.getSize().y);    //  set EACH time
    temp = trans.transformPoint({0, 0});
    DL.setPosition(temp);       //  moves to location relative to object (0, 0)
    DL.setRotation(DL.getRotation() - 45);
    rdrawhelp(DL, win);
    DR.setSize(size * Csize);
    DR.setOrigin(DR.getSize().x, DR.getSize().y);
    temp = trans.transformPoint({DR.getSize().x/Csize, 0});
    DR.setPosition(temp);
    DR.setRotation(DR.getRotation() + 45);
    rdrawhelp(DR, win);
}
void myDraw::rdrawhelp(myDraw& D, sf::RenderWindow& win) {
    sf::Transform transform = D.getTransform();
    sf::Vector2f temp;
    sf::Vector2f vectsize = D.getSize();
    sf::Color Orange(255, 69, 0);
    myDraw newDL;
    myDraw newDR;
    const float Csize = sin(M_PI/4);  //  "macro" to help with resize
    if (D.getreps() == 0)    //  null case
        return;

    win.draw(D);
    newDL = D;
    newDR = D;
    newDL.setSize(vectsize * Csize);  //  Left: HAVE to set size before origin
    newDL.setOrigin(0, newDL.getSize().y);  //  set EACH time
    temp = transform.transformPoint({0, 0});
    newDL.setPosition(temp);    //  moves to location relative to object (0, 0)
    newDL.setRotation(newDL.getRotation() - 45);
    newDL.setreps(D.getreps() - 1);
    switch ((D.getreps() % 6)) {  //  Fun colors
        case 0:
            newDR.setFillColor(sf::Color::Red);
            newDL.setFillColor(sf::Color::Red);
            break;
        case 1:
            newDR.setFillColor(Orange);
            newDL.setFillColor(Orange);
            break;
        case 2:
            newDR.setFillColor(sf::Color::Yellow);
            newDL.setFillColor(sf::Color::Yellow);
            break;
        case 3:
            newDR.setFillColor(sf::Color::Green);
            newDL.setFillColor(sf::Color::Green);
            break;
        case 4:
            newDR.setFillColor(sf::Color::Blue);
            newDL.setFillColor(sf::Color::Blue);
            break;
        case 5:
            newDR.setFillColor(sf::Color::Magenta);
            newDL.setFillColor(sf::Color::Magenta);
            break;
        default:
            break;
    }
    rdrawhelp(newDL, win);  //  recursive call
    newDR.setSize(vectsize * Csize);  //  Right
    //  set origin to bottom right for seemless rotation
    newDR.setOrigin(newDR.getSize().x, newDR.getSize().y);
    temp = transform.transformPoint({newDR.getSize().x/Csize, 0});
    newDR.setPosition(temp);
    newDR.setRotation(newDR.getRotation() + 45);  //  r
    newDR.setreps(newDR.getreps() - 1);
    rdrawhelp(newDR, win);  //  recurseive call
}


