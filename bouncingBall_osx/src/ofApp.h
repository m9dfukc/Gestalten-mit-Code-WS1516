#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Ball.h"

#define HOST "194.95.203.255"
#define PORT 12345

class ofApp : public ofBaseApp{
public:
    ofxOscSender sender;
    ofxOscReceiver receiver;
    Ball ball;
    
    void setup();
    void update();
    void draw();
    
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
};
