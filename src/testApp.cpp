#include "testApp.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"


//--------------------------------------------------------------
void testApp::setup(){

    //Setup fbos, canvas and objects needed
    grabber.initGrabber(640, 480);
    
    quad1.allocate(640, 480);
    quad2.allocate(640, 480);
    quad3.allocate(640, 480);
    quad4.allocate(640, 480);
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Read in serial from arduino plugs
    
    // Update FBOs according to selections
    quad1.begin();
    grabber.draw(0, 0);
    quad1.end();
    
    quad2.begin();
    grabber.draw(0, 0);
    quad2.end();
    
    quad3.begin();
    grabber.draw(0, 0);
    quad3.end();
    
    quad4.begin();
    grabber.draw(0, 0);
    quad4.end();
    
    // Update live view grabber
    grabber.update();
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    // Draw out the FBOs and any interface
    
    // Quad 1
    quad1.draw(grabber.width, 0, -grabber.width, grabber.height);
    
    // Quad 2
    quad2.draw(grabber.width*2, 0, -grabber.width, grabber.height);
    
    // Quad 3
    quad3.draw(grabber.width, grabber.height, -grabber.width, grabber.height);
    
    // Quad 4
    quad4.draw(grabber.width*2, grabber.height, -grabber.width, grabber.height);
    
    // Live view
    grabber.draw(grabber.width*1.25, grabber.height*.75, -320,240);
    
}




// Read in the string of chars from arduino plugs
string testApp::readSerial(){
    
}


// take the current quadrant's FBO and filter it according to the input from the arduino plug
void testApp::filterFbo(ofFbo &fbo, string inString){
    
}


// Function for each filter



//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}