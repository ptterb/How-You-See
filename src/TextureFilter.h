//
//  TextureFilter.h
//  howWeSee
//
//  Created by Tom Arthur on 5/3/13. Based off ofxFX Watercolors example.
//
//

#ifndef howWeSee_TextureFilter_h
#define howWeSee_TextureFilter_h

#include <iostream>
#include "ofMain.h"
#include "Filter.h"
#include "ofxFX.h"


#endif /* defined(__howWeSee__TextureFilter__) */

class TextureFilter : public Filter {
    
    
public:
    
    void update();
    void draw(float x, float y);
    string loadDesc(string name);
    
    TextureFilter();
    
    ofxGrayscale        grayscale;
    ofxGaussianBlur     blur;
    ofxNormals          normals;
    ofxDisplacePixels   disp;
    
    bool            bDrawVideo;
    bool            bDrawNormals;
    bool            bDrawField;
    bool            bCapture;
    
};