//
//  FacesFilter.h
//  howWeSee
//
//  Created by Brett Peterson on 4/29/13.
//
//

#ifndef __howWeSee__FacesFilter__
#define __howWeSee__FacesFilter__

#include <iostream>
#include "ofMain.h"
#include "Filter.h"
#include "ofxOpenCv.h"

#endif /* defined(__howWeSee__ColorFilter__) */

class FacesFilter : public Filter {
    
    
public:
    
    void update();
    void draw(float x, float y);
    
    FacesFilter();
    
    ofxCvHaarFinder finder;
    ofxCvColorImage camImage;
    ofxCvGrayscaleImage greyImage;
    ofImage spotMask;
    ofImage spotlight;
    
    int numFaces;
    
    float rotY = 0;
};