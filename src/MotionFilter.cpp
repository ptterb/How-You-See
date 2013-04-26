//
//  MotionFilter.cpp
//  howWeSee
//
//  Created by Brett Peterson on 4/25/13.
//
//

#include "MotionFilter.h"

MotionFilter::MotionFilter(){
    
    // This is where you set up the filter. Any variables that need to be allocated should be done here.
    
    colorImage.allocate(vWidth, vHeight);
    grayImage.allocate(vWidth, vHeight);
    grayDiff.allocate(vWidth, vHeight);
    
};

void MotionFilter::update(){
    
    // Update the grabber, update the filter
    grabber.update();
    
    if (grabber.isFrameNew()){
        colorImage.setFromPixels(grabber.getPixelsRef());
        colorImage.mirror(false, true);
        
        grayImage = colorImage;
        
        // Run differencing between last frame and this one
        grayDiff.absDiff(grayImage, lastImage);
        
        lastImage = grayImage;
    }
    
    // Draw into the FBO
    fbo.begin();
    grayDiff.draw(0, 0);
    fbo.end();
    
    
    
};

void MotionFilter::draw(float x, float y) {
    
    // Draw the filter to the screen.
    fbo.draw(x, y);
    
    
};