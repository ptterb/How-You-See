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
    
    void changeState();
    
    Filter();
    
    ofVideoGrabber grabber;
    ofFbo fbo;
    bool state;
    const float vWidth = 640;
    const float vHeight = 480;
};


