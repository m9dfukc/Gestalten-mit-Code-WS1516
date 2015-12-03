#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    string nameAndDate = "my name and a timestamp: " + ofGetTimestampString("%Y-%m-%d %H:%M:%S");
    cout << nameAndDate << endl;
    testImg.load("http://cdn.playbuzz.com/cdn/0079c830-3406-4c05-a5c1-bc43e8f01479/8c7524f9-b5f9-4ff6-8878-b6ed1a4085f5_560_420.jpg");

    ofxHttpForm form;
    form.action = "http://andreas-schmelas.de/gestaltenmitcode/formular.php";
    form.addFormField("name", nameAndDate);
    form.addFormField("email", "hello@helloworld.de");
    form.addFile("userfile", "cat.jpg");
    httpPostRequest.submitForm(form);
    
    ofHttpResponse dataTxt = ofLoadURL("http://andreas-schmelas.de/gestaltenmitcode/data.txt");
    vector<string> stringArray = ofSplitString(dataTxt.data, "\n");
    
    for (int i=0; i < stringArray.size(); i++) {
        cout << stringArray[i] << endl;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    testImg.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
