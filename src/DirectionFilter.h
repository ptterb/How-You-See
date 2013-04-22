//
//  DirectionFilter.h
//  howWeSee
//
//  Created by Brett Peterson on 4/21/13.
//
//

#ifndef __howWeSee__DirectionFilter__
#define __howWeSee__DirectionFilter__

#include <iostream>
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "Filter.h"

#endif /* defined(__howWeSee__DirectionFilter__) */

class DirectionFilter : public Filter {
    
    
public:
    
    void update();
    void draw(float x, float y);
    
    DirectionFilter();
    
    ofxCvContourFinder cf;
    
    ofxCvColorImage colorImage;
    ofxCvGrayscaleImage grayImage;
    ofImage displayGray;
    
};