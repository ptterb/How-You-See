#include "testApp.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"


//--------------------------------------------------------------
void testApp::setup(){
        
    grabber.initGrabber(vidWidth, vidHeight);
    
    // Add filters into the superclass array
    filters[0] = &color;
    filters[1] = &direction;
    filters[2] = &motion;
    filters[3] = &faces;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Update grabber for live view
    grabber.update();
    
    // Update only the filters that have been selected
    for (int i = 0; i < numFilters; i++){
        
        // Add other numbers (meaning filter is not being drawn) if taking too much memory. Right now its ok
        if (filters[i]->location != 0){
            filters[i]->update();
        }
    }
    
    unplugged1.update();
    unplugged2.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // TESTING. All the same or mutiple instances?
//    unplugged1.draw(0, 0);
//    unplugged1.draw(640, 0);
//    unplugged1.draw(0, 480);
//    unplugged1.draw(640, 480);

    // Draw out the filters that are chosen
    for (int i = 0; i < numFilters; i++){
        
        // Quad 1
        if (filters[i]->location == 1){
            filters[i]->draw(0,0);
        }
        
        // Quad 2
        else if (filters[i]->location == 2){
            filters[i]->draw(vidWidth,0);
        }
        
        // Quad 3
        else if (filters[i]->location == 3){
            filters[i]->draw(0,vidHeight);
        }
        
        // Quad 4
        else if (filters[i]->location == 4){
            filters[i]->draw(vidWidth,vidHeight);
        }
    }
    
    // Live view
    grabber.draw(grabber.width*1.25, grabber.height*.75, -320,240);
   
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    // Receive the key commands from the arduino leonardo to tell the app which plugs are plugged into what filter.
    switch (key) {
        case 'A':
            filters[3]->changeLoc(1);
            break;
        case 'B':
            filters[0]->changeLoc(2);
            break;
        case 'C':
            filters[3]->changeLoc(3);
            break;
        case 'D':
            filters[3]->changeLoc(4);
            break;
        case '1':
            filters[0]->changeLoc(0);
            break;
            
        case 'a':
            filters[1]->changeLoc(1);
            break;
        case 'b':
            filters[1]->changeLoc(2);
            break;
        case 'c':
            filters[1]->changeLoc(3);
            break;
        case 'd':
            filters[2]->changeLoc(4);
            break;
        case '2':
            filters[1]->changeLoc(0);
            break;
            
        default:
            break;
    }

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