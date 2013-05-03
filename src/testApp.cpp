#include "testApp.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"
#include "ofxFX.h"


//--------------------------------------------------------------
void testApp::setup(){
        
    grabber.initGrabber(vidWidth, vidHeight);
    
    // Add filters into the superclass array
    filters[0] = &color;
    filters[1] = &direction;
    filters[2] = &motion;
    filters[3] = &faces;
    filters[4] = &texture;
    
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
    
}

//--------------------------------------------------------------
void testApp::draw(){

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
            filters[0]->changeLoc(1);
            break;
        case 'B':
            filters[0]->changeLoc(2);
            break;
        case 'C':
            filters[0]->changeLoc(3);
            break;
        case 'D':
            filters[0]->changeLoc(4);
            break;
        case '1':
            filters[0]->changeLoc(0);
            break;
            
        case 'E':
            filters[1]->changeLoc(1);
            break;
        case 'F':
            filters[1]->changeLoc(2);
            break;
        case 'G':
            filters[1]->changeLoc(3);
            break;
        case 'H':
            filters[1]->changeLoc(4);
            break;
        case '2':
            filters[1]->changeLoc(0);
            break;
            
        case 'I':
            filters[2]->changeLoc(1);
            break;
        case 'J':
            filters[2]->changeLoc(2);
            break;
        case 'K':
            filters[2]->changeLoc(3);
            break;
        case 'L':
            filters[2]->changeLoc(4);
            break;
        case '3':
            filters[2]->changeLoc(0);
            break;
            
        case 'M':
            filters[3]->changeLoc(1);
            break;
        case 'N':
            filters[3]->changeLoc(2);
            break;
        case 'O':
            filters[3]->changeLoc(3);
            break;
        case 'P':
            filters[3]->changeLoc(4);
            break;
        case '4':
            filters[3]->changeLoc(0);
            break;
            
        case 'Q':
            filters[4]->changeLoc(1);
            break;
        case 'R':
            filters[4]->changeLoc(2);
            break;
        case 'S':
            filters[4]->changeLoc(3);
            break;
        case 'T':
            filters[4]->changeLoc(4);
            break;
        case '5':
            filters[4]->changeLoc(0);
            break;
            
        case 'U':
            filters[2]->changeLoc(1);
            break;
        case 'V':
            filters[2]->changeLoc(2);
            break;
        case 'W':
            filters[2]->changeLoc(3);
            break;
        case 'X':
            filters[2]->changeLoc(4);
            break;
        case '6':
            filters[2]->changeLoc(0);
            break;
        case'7':
            texture.bCapture = true;
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