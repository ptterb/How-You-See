#include "testApp.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    // UNCOMMENT WHEN WE'RE READY FOR SERIAL
    
    // mySerial.setup("/dev/cu.USA19H181P1.1", 9600);
//    if (serial.setup()) {
//        printf("serial connected");
//    }
    
    grabber.initGrabber(640, 480);
    
    // Add filters into the superclass array
    filters[0] = &color;
    filters[1] = &direction;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Read in serial from arduino plugs
    //unsigned char bytes = new unsigned char[4];
    //bytes = readSerial();
  
    
    // Update grabber for live view
    grabber.update();
    
    // Update filters according to selections
    // TODO only update the filters that have been selected and draw into the correct quads
    
    for (int i = 0; i < numFilters; i++){
        
        if (filters[i]->location != 0){
            filters[i]->update();
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

    // Draw out the filters and any interface
    
    for (int i = 0; i < numFilters; i++){
        if (filters[i]->location == 1){
            filters[i]->draw(0,0);
        }
        else if (filters[i]->location == 2){
            filters[i]->draw(640,0);
        }
        else if (filters[i]->location == 3){
            filters[i]->draw(0,480);
        }
        else if (filters[i]->location == 4){
            filters[i]->draw(640,480);
        }
    }
    
    // Quad 1
    //filters[0]->draw(0,0);
    //color.draw(0, 0);

    // Quad 2
    //direction.draw(direction.vWidth, 0);
   
    // Quad 3

    // Quad 4
    
    // Live view
    grabber.draw(grabber.width*1.25, grabber.height*.75, -320,240);
   
}


// Read in the string of chars from arduino plugs - example from oFx docs
unsigned char *testApp::readSerial(){

    int bytesRequired = 4;
    unsigned char bytes[bytesRequired];
    int bytesRemaining = bytesRequired;
    // loop until we've read everything
    while ( bytesRemaining > 0 )
    {
        // check for data
        if ( serial.available() > 0 )
        {
            // try to read - note offset into the bytes[] array, this is so
            // that we don't overwrite the bytes we already have
            int bytesArrayOffset = bytesRequired - bytesRemaining;
            int result = serial.readBytes( &bytes[bytesArrayOffset],
                                          bytesRemaining );
            
            // check for error code
            if ( result == OF_SERIAL_ERROR )
            {
                // something bad happened
                ofLog( OF_LOG_ERROR, "unrecoverable error reading from serial" );
                // bail out
                break;
            }
            else if ( result == OF_SERIAL_NO_DATA )
            {
                // nothing was read, try again
            }
            else
            {
                // we read some data!
                bytesRemaining -= result;
            }
        }
    }
}


// take the current quadrant's FBO and filter it according to the input from the arduino plug
void testApp::filterFbo(ofFbo &fbo, string inString){
    
}


// Function for each filter



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
            filters[1]->changeLoc(4);
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