#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "UniqueBall.h"
#include "ofxGui.h"

// define constants for use with OSC
// note: we're using the UDK network address here,
// you'll propably have to adapt the ip address to your local network
// for example 192.168.1.255
#define HOST "194.95.203.255"
#define PORT 12345

class ofApp : public ofBaseApp{
public:
    ofxOscSender sender;
    ofxOscReceiver receiver;
    UniqueBall ball;
    
    
    void setup();
    void update();
    void draw();
    
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
};
