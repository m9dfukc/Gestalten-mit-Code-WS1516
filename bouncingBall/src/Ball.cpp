//
//  Ball.cpp
//  emptyExample
//
//  Created by Andreas on 18.11.15.
//
//

#include "Ball.h"

void Ball::setup(float x, float y, float s) {
    posX = x;
    posY = y;
    speed = s;
}

void Ball::update() {
    posX += speed;
}

void Ball::draw() {
    ofBackground(0, 0, 0);
    ofDrawCircle(posX, posY, 10);
}