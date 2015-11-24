//
//  Ball.hpp
//  This is a very basic `Ball` class.
//  This class features 'default parameters' (see `init` function),
//  'method overloading' (see `setPosition` function) and
//  'operator overloading' (see `update` and `flipDirection` functions).
//
//  References:
//  http://www.learncpp.com/cpp-tutorial/77-default-parameters/
//  http://www.learncpp.com/cpp-tutorial/76-function-overloading/
//  http://www.learncpp.com/cpp-tutorial/91-introduction-to-operator-overloading/
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
    ofPoint velocity;
    float speed;
    
    Ball();
    void init(float x=0, float y=0, float s=1); // we use default params here
    void update();
    void draw();
    
    void flipDirectionX();
    void flipDirectionY();
    void setPosition(float x, float y);
    void setPosition(ofPoint p); // overloaded setPosition so we can feed either raw values of a ofPoint position
    ofPoint getPosition();
};

#endif /* Ball_hpp */