#pragma once

#include "ofMain.h"
#include "Filter.h"
#include "ColorFilter.h"
#include "DirectionFilter.h"
#include "MotionFilter.h"
#include "FacesFilter.h"
#include "DepthFilter.h"
#include "Unplugged.h"
#include "ofxKinect.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        ofVideoGrabber grabber;
        int vidWidth = 640;
        int vidHeight = 480;

        ofSerial serial;
    
        // Filter subclasses
        int numFilters = 5;
        ColorFilter color;
        DirectionFilter direction;
        MotionFilter motion;
        FacesFilter faces;
        DepthFilter depth;
    
        // Filter array
        Filter * filters[5];
    
    Unplugged unplugged1;
    Unplugged unplugged2;

};
