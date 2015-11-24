//
//  UniqueBall.cpp
//  emptyExample
//
//  Created by Andreas on 24.11.15.
//
//

#include "UniqueBall.h"

UniqueBall::UniqueBall() {
    Ball();
    uuid = UUIDGenerator::defaultGenerator().create().toString();
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void UniqueBall::draw() {
    ofSetColor(color);
    Ball::draw();
}