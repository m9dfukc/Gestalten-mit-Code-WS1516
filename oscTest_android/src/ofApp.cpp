#include "ofApp.h"

	
//--------------------------------------------------------------
void ofApp::setup(){
	sender.setup("192.168.1.255", 1234);
	receiver.setup(1234);
}

//--------------------------------------------------------------
void ofApp::exit(){
}

//--------------------------------------------------------------
void ofApp::update(){
	std::string timestamp = ofGetTimestampString("%Y-%m-%d %H:%M:%S:%i");
	ofxOscMessage m;
	m.setAddress("/timestamp");
	m.addStringArg(timestamp);
	sender.sendMessage(m, false);
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(50, 50, 50);
	while (receiver.hasWaitingMessages()) {
		ofxOscMessage m;
		receiver.getNextMessage(m);

		if (m.getAddress() == "/timestamp") {
			string timestamp = m.getArgAsString(0);
			ofDrawBitmapString(timestamp, 50, 50);
		}
	}
}
//--------------------------------------------------------------
void ofApp::networkConnectedEvent(bool &connected) {
	ofLog() << "network connected!";
}