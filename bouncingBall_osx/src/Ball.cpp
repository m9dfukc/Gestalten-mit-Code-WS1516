//
//  Ball.cpp
//  emptyExample
//
//  Created by Andreas on 18.11.15.
//
//

#include "Ball.h"

Ball::Ball() {
    
    position = ofPoint(0.0, 0.0);
    direction = ofPoint(ofRandomf(), ofRandomf());
    speed = 1;
}

void Ball::setup(float x, float y, float s) {
    position.set(x, y);
    speed = s;
}

void Ball::update() {
    position += direction * speed;
}

void Ball::draw() {
    ofBackground(0, 0, 0);
    ofDrawCircle(position, 10);
}

void Ball::flipDirectionX() {
    direction.x *= -1;
}
void Ball::flipDirectionY() {
    direction.y *= -1;
}

void Ball::setPosition(float x, float y) {
    position.set(x, y);
    direction.set(ofRandomf(), ofRandomf());
}

ofPoint Ball::getPosition() {
    return position;
}