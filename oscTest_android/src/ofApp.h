#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void exit();
	void networkConnectedEvent(bool &connected);

	ofxOscSender sender;
	ofxOscReceiver receiver;
};

