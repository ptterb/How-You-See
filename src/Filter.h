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
    //string loadDesc(string fileName);
    
    Filter();
    
    // Virtual functions. Need them to access child functions from pointer array
    virtual void update() = 0;
    virtual void draw(float x, float y) = 0;
    virtual string loadDesc(string name) = 0;
    
    ofVideoGrabber grabber;
    ofFbo fbo;
    int location = 0;
    const float vWidth = 640;
    const float vHeight = 480;
    
    string desc;
    string title;
};


