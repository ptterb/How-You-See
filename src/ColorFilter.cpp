//
//  ColorFilter.cpp
//  howWeSee
//
//  Created by Brett Peterson on 4/21/13.
//
//
//  **** Each filter will have at least 3 functions: the constructor, update and draw.
//  Each filter inherits from the Filter class which contains an FBO and video grabber to use.
//  Run any processing in the update function and draw it to the FBO. Then in the draw, just draw the FBO to the screen



#include "ColorFilter.h"


ColorFilter::ColorFilter(){
    
    // Load title and description
    title = "Color";
    desc = loadDesc("color");
    
    // This is where you set up the filter. Any variables that need to be allocated should be done here.
    
    colorImage.allocate(vWidth, vHeight);
    
    // Initialize fonts
    filterfont.loadFont("futura.ttf", 32, true);
};

void ColorFilter::update(){
    
    // Update the grabber, update the filter
    grabber.update();
    
    if (grabber.isFrameNew()){
        colorImage.setFromPixels(grabber.getPixelsRef());
        colorImage.mirror(false, true);
    }
    
    // Amp up saturation
    ofPixels pix = colorImage.getPixelsRef();
    for (int x =0; x < colorImage.width; x++) {
        for (int y=0; y < colorImage.height; y++){
            ofColor color = pix.getColor(x, y);
            
            color.setSaturation(200);
            
            pix.setColor(x, y, color);
        }
    }
    
    // Set the colorImage with the new saturated pixels
    colorImage.setFromPixels(pix);
    
    
    
    // Draw into the FBO
    fbo.begin();
    colorImage.draw(0, 0);
    filterfont.drawString("color", vWidth/2,400);
    fbo.end();
    
    
    
};

void ColorFilter::draw(float x, float y) {
    
    // Draw the filter to the screen.
    fbo.draw(x, y);


};

//--------------------------------------------------------------
string ColorFilter::loadDesc(string name){
    
    // Open the file, read in the text and return as a string
    ofFile file;
    
    file.open("../../../data/" + name + ".txt", ofFile::ReadOnly, false);
    ofBuffer buff = file.readToBuffer();
    
    return buff.getText();
    
}