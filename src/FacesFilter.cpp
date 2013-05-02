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
    
    //need this for alpha to come through
	ofEnableAlphaBlending();
    
    //allocate mem for images, setup Haar Finder
    camImage.allocate(grabber.width, grabber.height);
    spotMask.loadImage("spotlight.png");
    spotlight.allocate(vWidth, vHeight, OF_IMAGE_COLOR_ALPHA);
    blackTop.loadImage("blackTop.png");
    bottomLayer.loadImage("botlayer.png");
    finder.setup("haarcascade_frontalface_default.xml");
    
    maskShader.load("mask");
    maskShader.begin();
	maskShader.setUniformTexture("Tex0", blackTop.getTextureReference(), 0);
	maskShader.setUniformTexture("Tex1", spotMask.getTextureReference(), 1);
	maskShader.end();
    
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

    
//    // Draw into the FBO
//    fbo.begin();
//    ofEnableAlphaBlending();
//    ofClear(0, 0, 0);
//    
//    //Draw shadowy version
//    camImage.draw(0, 0);
//    ofSetColor(0, 0, 0, 230);
//    ofRect(0, 0, 640, 480);
//    ofSetColor(255, 255, 255);
//    
//    ofPixels camPix = grabber.getPixelsRef();
//    ofPixels outPix = spotlight.getPixelsRef();
//    spotlight.setFromPixels(camPix);
//    
//    // Draw spotlight on faces found
//	for(int i = 0; i < finder.blobs.size(); i++) {
//        ofRectangle current = finder.blobs[i].boundingRect;
//        
//        // Draw a subsection of camImage, hightlighting the face
//        // TODO - MAKE THIS LOOK BETTER
//        spotlight.drawSubsection(current.x, current.y, current.width, current.height, current.x, current.y);
//	}
//    
//    fbo.end();

    
};

void FacesFilter::draw(float x, float y) {
    
    // Draw the filter to the screen.
//    fbo.draw(x, y);
    
    
    ofPushMatrix();
    ofTranslate(x, y);
    //first draw the bottom layer
	camImage.draw(0, 0);
	
    
    // Draw spotlight on faces found
	for(int i = 0; i < finder.blobs.size(); i++) {
        
        if (i == 0) {
            ofRectangle current = finder.blobs[i].boundingRect;
            
            float centerX = current.x + (current.width/2);
            float centerY = current.y + (current.height/2);
            
            // Draw a subsection of camImage, hightlighting the face
            // TODO - MAKE THIS LOOK BETTER
            //spotlight.drawSubsection(current.x, current.y, current.width, current.height, current.x, current.y);
            
            
            //then draw a quad for the top layer using our composite shader to set the alpha
            maskShader.begin();
            
            //our shader uses two textures, the top layer and the alpha
            //we can load two textures into a shader using the multi texture coordinate extensions
            glActiveTexture(GL_TEXTURE0_ARB);
            blackTop.getTextureReference().bind();
            
            glActiveTexture(GL_TEXTURE1_ARB);
            spotMask.getTextureReference().bind();
            
            //draw a quad the size of the frame
            glBegin(GL_QUADS);
            
            //move the mask around with the mouse by modifying the texture coordinates
            
            glMultiTexCoord2d(GL_TEXTURE0_ARB, 0, 0);
            glMultiTexCoord2d(GL_TEXTURE1_ARB, 0-centerX + (spotMask.width/2), 0-centerY + (spotMask.height/2));
            glVertex2f( 0, 0);
            
            glMultiTexCoord2d(GL_TEXTURE0_ARB, blackTop.getWidth(), 0);
            glMultiTexCoord2d(GL_TEXTURE1_ARB, 0-centerX + spotMask.width + (spotMask.width/2), 0-centerY + (spotMask.height/2));
            glVertex2f( blackTop.getWidth(), 0);
            
            glMultiTexCoord2d(GL_TEXTURE0_ARB, blackTop.getWidth(), blackTop.getHeight());
            glMultiTexCoord2d(GL_TEXTURE1_ARB, 0-centerX + spotMask.width + (spotMask.width/2), 0-centerY + spotMask.height + (spotMask.height/2));
            glVertex2f( blackTop.getWidth(), blackTop.getHeight());
            
            glMultiTexCoord2d(GL_TEXTURE0_ARB, 0, blackTop.getHeight());
            glMultiTexCoord2d(GL_TEXTURE1_ARB, 0-centerX + (spotMask.width/2), 0-centerY + spotMask.height + (spotMask.height/2));
            glVertex2f( 0, blackTop.getHeight() );
            
            glEnd();
            
            //deactive and clean up
            glActiveTexture(GL_TEXTURE1_ARB);
            spotMask.getTextureReference().unbind();
            
            glActiveTexture(GL_TEXTURE0_ARB);
            spotMask.getTextureReference().unbind();
            
            maskShader.end();
        }
        
	}
    
    ofPopMatrix();
    
    
	
    
    
    
};