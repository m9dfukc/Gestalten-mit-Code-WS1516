#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ball.init(100, 100, 5);
    cout << ball.position.x << endl;
    
    sender.setup(HOST, PORT);
    sender.enableBroadcast();
    receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofPoint position = ball.getPosition();
    if (position.x <= 0 || position.x >= ofGetWindowWidth()) {
        
        ofxOscMessage m;
        m.setAddress("/ball");
        m.addFloatArg(position.x);
        m.addFloatArg(position.y);
        sender.sendMessage(m);
        
        ball.flipDirectionX();
    }
    if (position.y <= 0 || position.y >= ofGetWindowHeight()) {
        
        ofxOscMessage m;
        m.setAddress("/ball");
        m.addFloatArg(position.x);
        m.addFloatArg(position.y);
        sender.sendMessage(m);
        
        ball.flipDirectionY();
    }
    
    ball.update();
    
    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        if(m.getAddress() == "/ball"){
            float oscPositionX = m.getArgAsFloat(0);
            float oscPositionY = m.getArgAsFloat(1);
            //ball.setPosition(oscPositionX, oscPositionY);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ball.draw();
}

void ofApp::mousePressed(int x, int y, int button) {
    ball.setPosition(x, y);
}

void ofApp::mouseReleased(int x, int y, int button) {
    
}