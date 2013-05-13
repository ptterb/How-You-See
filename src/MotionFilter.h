//
//  MotionFilter.h
//  howWeSee
//
//  Created by Brett Peterson on 4/25/13.
//
//

#ifndef __howWeSee__MotionFilter__
#define __howWeSee__MotionFilter__

#include <iostream>
#include "ofMain.h"
#include "Filter.h"
#include "ofxOpenCv.h"

#endif /* defined(__howWeSee__ColorFilter__) */

class MotionFilter : public Filter {
    
    
public:
    
    void update();
    void draw(float x, float y);
    string loadDesc(string name);
    
    MotionFilter();
    
    ofxCvColorImage colorImage;
    ofxCvGrayscaleImage grayImage;
    ofxCvGrayscaleImage lastImage;
    ofxCvGrayscaleImage grayDiff;
    
    
};