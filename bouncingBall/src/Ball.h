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
    float posX;
    float posY;
    float speed;
    
    void setup(float x, float y, float s);
    void update();
    void draw();
    
    
};

#endif /* Ball_hpp */
