#pragma once

#include "ofMain.h"
#include "Filter.h"
#include "ColorFilter.h"
#include "DirectionFilter.h"

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
    
        unsigned char *readSerial();
        void filterFbo(ofFbo &fbo, string inString);

        ofVideoGrabber grabber;
        ofFbo quad1;
        ofFbo quad2;
        ofFbo quad3;
        ofFbo quad4;

        ofSerial serial;
    
        // Filter subclasses
        ColorFilter color;
        DirectionFilter direction;
};
