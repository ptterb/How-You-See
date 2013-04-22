//
//  Filter.cpp
//  howWeSee
//
//  Created by Brett Peterson on 4/21/13.
//
//

#include "Filter.h"

Filter::Filter(){
    
    // Allocate the grabber and FBO
    grabber.initGrabber(vWidth, vHeight);
    fbo.allocate(vWidth, vHeight);
    
    // Don't run the filter unless it's ready to be drawn to the screen. Default is off.
    state = false;
    
}

void Filter::changeState(){
    
    state = !state;
    
}