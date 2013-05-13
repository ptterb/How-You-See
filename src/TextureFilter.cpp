//
//  TextureFilter.cpp
//  howWeSee
//
//  Created by Tom Arthur on 5/3/13. Based off ofxFX Watercolors example.
//
//

#include "TextureFilter.h"

TextureFilter::TextureFilter(){
    
    // This is where you set up the filter. Any variables that need to be allocated should be done here.
    
    // Load title and description
    title = "Texture";
    desc = loadDesc("texture");
    
    grayscale.allocate(vWidth, vHeight);
    blur.allocate(vWidth, vHeight);
    blur.setRadius(10);
    blur.setPasses(20);
    normals.allocate(vWidth, vHeight);
    disp.allocate(vWidth, vHeight);
    
    bDrawVideo = false;
    bDrawField = false;
    bDrawNormals = true;
    
    bCapture = true;
    
};

void TextureFilter::update(){
    
    // Update the grabber, update the filter
    grabber.update();
    
    if (grabber.isFrameNew()){
        grayscale.setTexture(grabber.getTextureReference());
        grayscale.update();
        blur << grayscale;
        blur.update();
        normals << blur;
        normals.update();
    }
    
    //capture initial frame to 
    if (bCapture){
        disp.getBackBuffer()->begin();
        ofSetColor(255);
        grabber.draw(0, 0);
        disp.getBackBuffer()->end();
        
        bCapture = false;
    }

    disp.setTexture(normals.getTextureReference());
    disp.update();
    
    // Draw into the FBO
    fbo.begin();
        
    ofSetColor(255);
    disp.draw(0,0,vWidth,vHeight);

    if ( bDrawNormals ){
        ofSetColor(255);
        normals.draw(0,0);
    }
    fbo.end();

}
    
    

void TextureFilter::draw(float x, float y) {
    
    // Draw the filter to the screen.
    fbo.draw(x + vWidth, y, -vWidth, vHeight);
    

}

//--------------------------------------------------------------
string TextureFilter::loadDesc(string name){
    
    // Open the file, read in the text and return as a string
    ofFile file;
    
    file.open("../../../data/" + name + ".txt", ofFile::ReadOnly, false);
    ofBuffer buff = file.readToBuffer();
    
    return buff.getText();
    
}
