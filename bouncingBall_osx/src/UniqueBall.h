//
//  UniqueBall.h
//  This class extends the base class `Ball` and adds a
//  unique id and a random color. We will need this as a
//  unique id handle for OSC.
//
//  Created by Andreas on 24.11.15.
//
//

#ifndef UniqueBall_h
#define UniqueBall_h

#include "ofMain.h"
#include "Poco/UUIDGenerator.h"
#include "Poco/UUID.h"
#include "Ball.h"

using Poco::UUIDGenerator;

class UniqueBall : public Ball{
public:
    string uuid;
    ofColor color;
    
    UniqueBall();
    void draw();
};



#endif /* UniqueBall_h */
