//
//  ColorFilter.h
//  howWeSee
//
//  Created by Brett Peterson on 4/21/13.
//
//

#ifndef __howWeSee__ColorFilter__
#define __howWeSee__ColorFilter__

#include <iostream>
#include "ofMain.h"
#include "Filter.h"
#include "ofxOpenCv.h"

#endif /* defined(__howWeSee__ColorFilter__) */

class ColorFilter : public Filter {
    
    
public:
    
    void update();
    void draw(float x, float y);
    string loadDesc(string name);
    
    ColorFilter();
    
    ofxCvColorImage colorImage;
    
    // Filter text
    ofTrueTypeFont filterfont;
    
};