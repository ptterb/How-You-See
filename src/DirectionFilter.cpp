//
//  DirectionFilter.cpp
//  howWeSee
//
//  Created by Brett Peterson on 4/21/13.
//
//

#include "DirectionFilter.h"

DirectionFilter::DirectionFilter(){
    
    // This is where you set up the filter. Any variables that need to be allocated should be done here.
    
    colorImage.allocate(vWidth, vHeight);
    grayImage.allocate(vWidth, vHeight);
    displayGray.allocate(vWidth, vHeight, OF_IMAGE_GRAYSCALE);
};

void DirectionFilter::update(){
    
    // Update the grabber, update the filter
    grabber.update();
    
    if (grabber.isFrameNew()){
        colorImage.setFromPixels(grabber.getPixelsRef());
        colorImage.mirror(false, true);
        grayImage = colorImage;
        grayImage.threshold(100);
        
        // Find the contours. Change these Settings to alter the contours displayed.
        // NOTE: I edited the findContours function to remove the bounding boxes.
        cf.findContours(grayImage, 1, grayImage.width*grayImage.height/2, 10, false);
        
        // Print number of blobs
        ofLogNotice() << cf.nBlobs;
        if (cf.nBlobs > 0){
            ofLogNotice() << cf.nBlobs;
        }
    }
    
    // Draw into the FBO at 0,0
    fbo.begin();
    colorImage.draw(0, 0);
    cf.draw(0,0,vWidth, vHeight);
    fbo.end();
    
    
    
};

void DirectionFilter::draw(float x, float y) {
    
    // Draw the filter to the screen.
    fbo.draw(x, y);
    
    
};