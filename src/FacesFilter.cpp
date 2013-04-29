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
    
    //allocate mem for image, setup Haar Finder
    camImage.allocate(grabber.width, grabber.height);
    finder.setup("haarcascade_frontalface_default.xml");
    
};

void FacesFilter::update(){
    
    // Update the grabber, update the filter
    grabber.update();
    
    if (grabber.isFrameNew()){
        camImage.setFromPixels(grabber.getPixelsRef());
        greyImage = camImage;
        finder.findHaarObjects(greyImage, 150,150);

    }
    
    
    // DEBUGGING
    numFaces = finder.blobs.size();
    
    //ofLogNotice() << numFaces;

    
    // Draw into the FBO
    fbo.begin();
    camImage.draw(0, 0);
    // Draw party hat on the first face found
	for(int i = 0; i < finder.blobs.size(); i++) {
        ofRectangle current = finder.blobs[i].boundingRect;
        ofRect(current.x, current.y, current.width, current.height);
	}
    fbo.end();
    
    
    
};

void FacesFilter::draw(float x, float y) {
    
    // Draw the filter to the screen.
    fbo.draw(x, y);
    
    
};