#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    vector<cv::Vec2f> lines;
    vector<cv::Vec3f> circles;
    
    ofVideoGrabber cam;
    
};
