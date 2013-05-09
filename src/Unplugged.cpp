//
//  Unplugged.cpp
//  howWeSee
//
//  Created by Brett Peterson on 5/3/13.
//
//

#include "Unplugged.h"


Unplugged::Unplugged() {

    lineSpeed = ofRandom(1, 10);
    // Use color image alpha so we can overlay instructions
    staticImage.allocate(640, 480, OF_IMAGE_COLOR_ALPHA);
    lastLine = 0;
    lineY = 480;
};

void Unplugged::update(){
    
    //STATIC NOISE
    // Loop through pixel array of image and assign a random grayscale value for each one.
    ofPixels pix = staticImage.getPixelsRef();
    
    for (int x = 0; x < staticImage.width; x++) {
        for (int y = 0; y < staticImage.height; y++){
            
            ofColor color = ofColor(ofRandom(0, 200), 255);
            pix.setColor(x, y, color);
        }
    }
    
    staticImage.setFromPixels(pix);
    
};

void Unplugged::draw(float x, float y){
    
    ofPushMatrix();
    ofTranslate(x, y);
    
    // Draw it al/ out
    staticImage.draw(0, 0);
    
    
    //TRACKING LINE
    //draw a tracking line that will move from bottom to top.
    
    
    ofLine(0, lineY, 640, lineY);
    
    if (lineY <= 0){
        lineY = 480;
    }
    else {
        lineY = lineY - lineSpeed;
    }

    //ofLogNotice() << lineY;
    
    ofPopMatrix();
};