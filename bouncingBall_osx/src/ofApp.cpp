#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    // initialize start position and speed of our ball;
    ball.init(100, 100, 5);
    
    // initialize OSC sender and broadcast to the whole network
    sender.setup(HOST, PORT);
    sender.enableBroadcast();
    
    // initialize OSC receiver on the same port as the sender
    receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    // change the direction of our ball if it hits the bounding borders
    ofPoint position = ball.getPosition();
    if (position.x <= 0 || position.x >= ofGetWindowWidth()) {
        ball.flipDirectionX();
    }
    if (position.y <= 0 || position.y >= ofGetWindowHeight()) {
        ball.flipDirectionY();
    }
    
    // call update of the ball object every frame!!
    ball.update();
    
    
    // ----- OSC stuff below here: -----
    
    // here we go and send our ball object id and position over the wire (via osc)
    ofxOscMessage m;
    m.setAddress("/ball");
    m.addStringArg(ball.uuid);
    m.addFloatArg(position.x);
    m.addFloatArg(position.y);
    
    sender.sendMessage(m);
    
    
    // here we receive the ids and positions of the other 'balls' in the network,
    // right now we just print these to the console ... we'll add the `draw` functionality
    // in our upcomming lessons!
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        if(m.getAddress() == "/ball"){
            string oscBallId = m.getArgAsString(0);
            float oscPositionX = m.getArgAsFloat(1);
            float oscPositionY = m.getArgAsFloat(2);
            
            if (oscBallId != ball.uuid) { // don not log out 'local' ball to the console!
                
                bool ballExists;
                
                for(int i=0; i < oscBalls.size(); i++) {
                    ballExists = (oscBalls[i].uuid == oscBallId);
                    if (ballExists) {
                        oscBalls[i].setPosition(oscPositionX, oscPositionY);
                        break;
                    }
                }
                
                if (!ballExists) {
                    UniqueBall oscBall;
                    oscBall.init();
                    oscBall.uuid = oscBallId;
                    oscBall.color = ofColor(128, 128, 128);
                    oscBall.setPosition(oscPositionX, oscPositionY);
                    oscBalls.push_back(oscBall);
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(235, 235, 235);
    
    // call the draw function of our ball object
    for(int i=0; i < oscBalls.size(); i++) {
        oscBalls[i].draw();
    }
    
    ball.draw();
}

void ofApp::mousePressed(int x, int y, int button) {
    ball.setPosition(x, y);
}

void ofApp::mouseReleased(int x, int y, int button) {
    
}