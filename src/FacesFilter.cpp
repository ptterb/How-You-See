//
//  FacesFilter.cpp
//  howWeSee
//
//  Created by Brett Peterson on 4/29/13.
//
//

#include "FacesFilter.h"

FacesFilter::FacesFilter(){
    
    // This is where you set up the filter. Any variables that need to be allocated should be done here.
    
    //allocate mem for images, setup Haar Finder
    camImage.allocate(grabber.width, grabber.height);
    spotMask.allocate(400,400, OF_IMAGE_COLOR_ALPHA);
    spotMask.loadImage("spotlight.png");
    spotlight.allocate(vWidth, vHeight, OF_IMAGE_COLOR_ALPHA);
    finder.setup("haarcascade_frontalface_default.xml");
    
};

void FacesFilter::update(){
    
    // Update the grabber, update the filter
    grabber.update();
    
    if (grabber.isFrameNew()){
        camImage.setFromPixels(grabber.getPixelsRef());
        greyImage = camImage;
        
        // ADJUST THE NUMBERS TO FIND SMALLER FACES IF NECESSARY
        finder.findHaarObjects(greyImage, 150,150);

    }
    
    
    // DEBUGGING
    //numFaces = finder.blobs.size();
    //ofLogNotice() << numFaces;

    
    // Draw into the FBO
    fbo.begin();
    ofEnableAlphaBlending();
    ofClear(0, 0, 0);
    
    //Draw shadowy version
    camImage.draw(0, 0);
    ofSetColor(0, 0, 0, 230);
    ofRect(0, 0, 640, 480);
    ofSetColor(255, 255, 255);
    
    ofPixels camPix = grabber.getPixelsRef();
    ofPixels outPix = spotlight.getPixelsRef();
    spotlight.setFromPixels(camPix);
    
    // Draw spotlight on faces found
	for(int i = 0; i < finder.blobs.size(); i++) {
        ofRectangle current = finder.blobs[i].boundingRect;
        
        // Draw a subsection of camImage, hightlighting the face
        // TODO - MAKE THIS LOOK BETTER
        spotlight.drawSubsection(current.x, current.y, current.width, current.height, current.x, current.y);
	}
    
    fbo.end();
    
    
    
};

void FacesFilter::draw(float x, float y) {
    
    // Draw the filter to the screen.
    fbo.draw(x, y);
    
    
};