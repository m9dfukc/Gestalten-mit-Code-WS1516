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
    velocity = ofPoint(ofRandomf(), ofRandomf());
    speed = 1;
}

void Ball::init(float x, float y, float s) {
    position.set(x, y);
    speed = s;
}

void Ball::update() {
    position += velocity * speed; // operator overloading
}

void Ball::draw() {
    ofBackground(235, 235, 235);
    ofDrawCircle(position, 10);
}

void Ball::flipDirectionX() {
    velocity.x *= -1; // operator overloading
}
void Ball::flipDirectionY() {
    velocity.y *= -1; // operator overloading
}

void Ball::setPosition(float x, float y) {
    position.set(x, y);
    velocity.set(ofRandomf(), ofRandomf());
}

void Ball::setPosition(ofPoint p) {
    setPosition(p.x, p.y);
}

ofPoint Ball::getPosition() {
    return position;
}