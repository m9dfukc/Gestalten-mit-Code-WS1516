#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ball = *new Ball();
    ball.setup(100, 100, 1);
    
    cout << ball.posX << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    ball.update();
    cout << ball.posX << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ball.draw();
}