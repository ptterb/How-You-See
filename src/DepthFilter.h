//
//  DepthFilter.h
//  howWeSee
//
//  Created by Brett Peterson on 5/3/13.
//
//

#ifndef __howWeSee__DepthFilter__
#define __howWeSee__DepthFilter__

#include <iostream>
#include "ofMain.h"
#include "Filter.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"

#endif /* defined(__howWeSee__DepthFilter__) */


class DepthFilter : public Filter {
    
    
public:
    
    
    DepthFilter();
    void update();
    void draw(float x, float y);
    string loadDesc(string name);
    
    void exit();
	
	void drawPointCloud();
	
	void keyPressed(int key);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
    
    ofxKinect kinect;
	
    //ADJUST WHEN SET IN FRAME
	int angle = -20;
    
    // used for viewing the point cloud
	ofEasyCam easyCam;
    
    float degrees = 10;
    float tilt = -1;
    int lastSwitch = 0;
    int panInterval = 3;
    int dir = 1;
    float maxDeg = 400;
    float minDeg = -200;

};