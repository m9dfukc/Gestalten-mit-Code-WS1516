#pragma once
#include "ofThread.h"

class Counter : public ofThread {
public:
    Counter();
    void start();
    void stop();
    void threadedFunction();
    int getCount();

protected:
    int count;
};
