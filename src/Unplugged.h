//
//  Unplugged.h
//  howWeSee
//
//  Created by Brett Peterson on 5/3/13.
//
//

#ifndef __howWeSee__Unplugged__
#define __howWeSee__Unplugged__

#include <iostream>
#include "ofMain.h"

#endif /* defined(__howWeSee__Unplugged__) */


class Unplugged {
    
    
public:
    
    
    Unplugged();
    
    void update();
    void draw(float x, float y);
    
    ofImage staticImage;
    float lineSpeed;
    int lastLine;
int lineY;

};