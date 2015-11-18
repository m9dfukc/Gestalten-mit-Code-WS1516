#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Ball.h"

class ofApp : public ofBaseApp{
public:
    Ball ball;
    void setup();
    void update();
    void draw();
};
