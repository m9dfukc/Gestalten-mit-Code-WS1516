//
//  Counter.cpp
//  threadsBeginner_osx
//
//  Created by Andreas on 16.12.15.
//
//

#include "Counter.h"

Counter::Counter() {
    count = 0;
}

void Counter::start() {
    startThread();
}

void Counter::stop() {
    stopThread();
}

void Counter::threadedFunction() {
    while(isThreadRunning()) {
        if ( lock() ) {
            count++;
            sleep(1000);
            unlock();
        }
    }
}

int Counter::getCount() {
    return count;
}