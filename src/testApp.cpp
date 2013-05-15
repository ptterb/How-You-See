#include "testApp.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"
#include "ofxFX.h"


//--------------------------------------------------------------
void testApp::setup(){
        
    // WHEN RUNNING ON LAPTOP WITH BUILT-IN CAMERA, UNCOMMENT THE FOLLOWING LINE
    //grabber.setDeviceID(1);
    grabber.initGrabber(vidWidth, vidHeight);
    
    // Add filters into the superclass array
    filters[0] = &texture;
    filters[1] = &faces;
    filters[2] = &depth;
    filters[3] = &direction;
    filters[4] = &color;
    filters[5] = &motion;
    
    // Load descriptions of each filter
    ofLogNotice() << filters[4]->title;
    ofLogNotice() << filters[4]->desc;
    
    // Initialize fonts
    filterTitle.loadFont("Gotham-Bold.ttf", 32, true);
    filterDesc.loadFont("Gotham-Medium.ttf", 16, true);

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
    ofBackground(0,0,0);
    ofPushMatrix();
    ofTranslate(320, 60); // Center on external screen. Also set in app preferences to open at 900x1440
    
    // TESTING. All the same or mutiple instances?
//    unplugged1.draw(0, 0);
//    unplugged1.draw(640, 0);
//    unplugged1.draw(0, 480);
//    unplugged1.draw(640, 480);

    // Draw out the filters that are chosen.
    // The frame size and offset and included here to position the filters correctly.
    // This looks confusing, so edit the frameSize and x/yOffset to move them around
    for (int i = 0; i < numFilters; i++){
        
        int stringLen = filterTitle.stringWidth(filters[i]->title);
        int titleHeight = filterTitle.stringHeight(filters[i]->title);
        
        // Quad 1
        if (filters[i]->location == 1){
            
            // Title
            filterTitle.drawString(filters[i]->title, -titleOffsetX, -titleOffsetY);
            
            // Description
            filterDesc.drawString(filters[i]->desc, -titleOffsetX, -titleOffsetY + titleHeight );
            
            // Frame
            ofRect(-frameSize - xOffSet, -frameSize - yOffset, vidWidth + (frameSize * 2) , vidHeight + (frameSize * 2));
            
            // Filter
            filters[i]->draw(-xOffSet, -yOffset);
        }
        
        // Quad 2
        else if (filters[i]->location == 2){
            
            // Title
            filterTitle.drawString(filters[i]->title, (vidWidth * 2) + titleOffsetX - stringLen, -titleOffsetY);
            
            // Description
            
            // Frame
            ofRect(vidWidth - frameSize + xOffSet, -frameSize - yOffset, vidWidth + (frameSize * 2) , vidHeight + (frameSize * 2));
            
            // Filter
            filters[i]->draw(vidWidth + xOffSet, -yOffset);
        }
        
        // Quad 3
        else if (filters[i]->location == 3){
            
            // Title
            filterTitle.drawString(filters[i]->title, -titleOffsetX, vidHeight + (yOffset * 2) + titleOffsetY);
            
            // Description
            
            // Frame
            ofRect(-frameSize - xOffSet, vidHeight - frameSize + yOffset, vidWidth + (frameSize * 2) , vidHeight + (frameSize * 2));
            
            // Filter
            filters[i]->draw(-xOffSet, vidHeight + yOffset);
        }
        
        // Quad 4
        else if (filters[i]->location == 4){
            
            // Title
            filterTitle.drawString(filters[i]->title, (vidWidth * 2) + titleOffsetX - stringLen, vidHeight + (yOffset * 2) + titleOffsetY);
            
            // Description
            
            // Frame
            ofRect(vidWidth - frameSize + xOffSet, vidHeight - frameSize + yOffset, vidWidth + (frameSize * 2) , vidHeight + (frameSize * 2));
            
            // Filter
            filters[i]->draw(vidWidth + xOffSet, vidHeight + yOffset);
        }
    }
    
    // Live view
    ofSetColor(0, 0, 0);
    ofRect((grabber.width*1.25)+frameSize, (grabber.height*.75)-frameSize, -320 - (frameSize * 2),240 + (frameSize * 2));
    ofSetColor(255, 255, 255);
    grabber.draw(grabber.width*1.25, grabber.height*.75, -320,240);
    
    ofPopMatrix();
   
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    // Receive the key commands from the arduino leonardo to tell the app which plugs are plugged into what filter.
    switch (key) {
            
        // TEXTURE
        case 'A':
            filters[0]->changeLoc(2);
            break;
        case 'B':
            filters[0]->changeLoc(1);
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
         
        // FACES
        case 'E':
            filters[1]->changeLoc(2);
            break;
        case 'F':
            filters[1]->changeLoc(1);
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
            
        // DEPTH
        case 'I':
            filters[2]->changeLoc(2);
            break;
        case 'J':
            filters[2]->changeLoc(1);
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
            
        // DIRECTION
        case 'M':
            filters[3]->changeLoc(2);
            break;
        case 'N':
            filters[3]->changeLoc(1);
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
         
        // COLOR
        case 'Q':
            filters[4]->changeLoc(2);
            break;
        case 'R':
            filters[4]->changeLoc(1);
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
           
        // MOTION
        case 'U':
            filters[5]->changeLoc(2);
            break;
        case 'V':
            filters[5]->changeLoc(1);
            break;
        case 'W':
            filters[5]->changeLoc(3);
            break;
        case 'X':
            filters[5]->changeLoc(4);
            break;
        case '6':
            filters[5]->changeLoc(0);
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