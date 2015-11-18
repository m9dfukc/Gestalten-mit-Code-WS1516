#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    // put 10 int o global variable number (see header file)
    number = 10;
    // to console
    cout << number << endl;
    
    // put 10 into the test function
    test(number);
    // should print now 100 because we passed by `reference`
    cout << number << endl;
    
    // here we instantiate a new Object, new = means we have to manually clear our memory
    myVector = new ofVec2f(40.0, 20.0);
    cout << myVector->length() << endl; // gives us the length of the vector
    
    delete myVector; // now let's free the memory with `delete`
    cout << myVector->length() << endl; // 'content' of myVector is now empty, Console just shows the memory address where we defined the myVector (header file)!
    
    // we can save data inside bytes (same as unisgned char) to save memory space
    unsigned char testByte = 10;
    cout << testByte << endl;
    cout << typeid(testByte).name() << endl; // let's get the type of out varaibale printed in the console
    
    // trying the new and fancy auto keyword (google for yourself!)
    auto testAuto = 1;
    cout << testAuto << endl;
    cout << typeid(testAuto).name() << endl; // let's get the type
    
    cout << sizeof(testAuto) << endl; // using the sizeof to get the size (in bytes) of a variable
    
    int lengthOfOutArray = sizeof(myArray) / 4; // we can use sizeof + the memory type of the array (4bytes in case of integer) to count the elements of an array
    cout << lengthOfOutArray << endl;
    for (int i=0; i<lengthOfOutArray; i++) {
        myArray[i] = i; // store 0 - 10 in our array ... I know, doesn't nmake sense
    }
    
    cout << myArray[0] << endl; // access the first eelement in our array.
}

// test method gets myNumber by `reference` (see &)
void ofApp::test(int &myNumber) {
    cout << myNumber << endl; // should show what we put in
    myNumber = 100; // write 100 to the reference coming in, see the "side-effect" this has!
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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