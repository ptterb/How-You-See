//
//  Filter.h
//  howWeSee
//
//  Created by Brett Peterson on 4/21/13.
//
//

#pragma once

#ifndef __howWeSee__Filter__
#define __howWeSee__Filter__

#include <iostream>
#include "ofMain.h"

#endif /* defined(__howWeSee__Filter__) */


class Filter {
    
    
public:
    
    void changeLoc(int _location);
    
    Filter();
    
    virtual void update() = 0;
    virtual void draw(float x, float y) = 0;
    
    ofVideoGrabber grabber;
    ofFbo fbo;
    int location = 0;
    const float vWidth = 640;
    const float vHeight = 480;
};


