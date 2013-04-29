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
    //camImage.draw(0, 0);
    ofSetColor(10, 10, 10, 200);
    //ofRect(0, 0, 640, 480);
    ofSetColor(255, 255, 255);
    
    ofPixels camPix = grabber.getPixelsRef();
    ofPixels outPix = spotlight.getPixelsRef();
    spotlight.setFromPixels(camPix);
    
    // Draw spotlight on faces found
	for(int i = 0; i < finder.blobs.size(); i++) {
        ofRectangle current = finder.blobs[i].boundingRect;
        
        spotlight.drawSubsection(current.x, current.y, current.width, current.height, current.x, current.y);
        
        //spotMask.resize(current.width, current.height);
        

//        ofPixels camPix = camImage.getPixelsRef();
//        ofPixels maskPix = spotMask.getPixelsRef();
//        ofPixels outPix = spotlight.getPixelsRef();
//        
//        for (int x = current.x; x < current.width; x++){
//            for (int y = current.y; y < current.height; y++) {
//                
////                ofColor maskColor = maskPix.getColor(x-current.x, y-current.y);
//                ofColor camColor = camPix.getColor(x, y);
////                ofColor newColor = ofColor(camColor, maskColor.a);
//                
//                outPix.setColor(x, y, camColor);
//            
//            }
//        }
//        
//        spotlight.setFromPixels(outPix);
//        spotlight.draw(0,0);
        
        ofSetColor(255, 255, 255, 200);
        //ofRect(current.x, current.y, current.width, current.height);
        ofSetColor(255, 255, 255);
	}
    
    fbo.end();
    
    
    
};

void FacesFilter::draw(float x, float y) {
    
    // Draw the filter to the screen.
    fbo.draw(x, y);
    
    
};