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
    
    // WHEN RUNNING ON LAPTOP WITH BUILT-IN CAMERA, UNCOMMENT THE FOLLOWING LINE
    //grabber.setDeviceID(1);
    grabber.initGrabber(vWidth, vHeight);
    fbo.allocate(vWidth, vHeight);
    
    // Don't run the filter unless it's ready to be drawn to the screen. Default is off.
    location = 0;
    
};

void Filter::changeLoc(int _location){
    
    location = _location;
    
};

////--------------------------------------------------------------
//string Filter::loadDesc(string name){
//    
//    // Open the file, read in the text and return as a string
//    ofFile file;
//    
//    file.open("../../../data/color.txt", ofFile::ReadOnly, false);
//    ofBuffer buff = file.readToBuffer();
//    
//    return buff.getText();
//    
//}

