//
//  Ball.hpp
//  emptyExample
//
//  Created by Andreas on 18.11.15.
//
//

#ifndef Ball_h
#define Ball_h

#include "ofMain.h"

class Ball {
public:
    
    ofPoint position;
    ofPoint direction;
    float speed;
    
    Ball();
    void setup(float x, float y, float s);
    void update();
    void draw();
    
    void flipDirectionX();
    void flipDirectionY();
    
    void setPosition(float x, float y);
    ofPoint getPosition();
};

#endif /* Ball_hpp */