//
//  DepthFilter.cpp
//  howWeSee
//
//  Created by Brett Peterson on 5/3/13.
//
//

#include "DepthFilter.h"




DepthFilter::DepthFilter(){
    
    // Load title and description
    title = "Depth";
    desc = loadDesc("depth");
    
    // enable depth->video image calibration
	kinect.setRegistration(true);
	kinect.init();
	kinect.open();		// opens kinect
    
	ofSetFrameRate(60);
    
	// Move to angle we want. once mounted, this shouldn't move
	kinect.setCameraTiltAngle(angle);
};

void DepthFilter::update(){
	
	kinect.update();
    
    // AutoPan the camera
    if (dir) {
        if (degrees <= maxDeg) {
            degrees += 10;
        }
    }
    else {
        if (degrees >= minDeg){
            degrees -= 10;
        }
    }
    
    
};

void DepthFilter::draw(float x, float y){
    
    fbo.begin();
    ofClear(0, 0, 0, 0);
    easyCam.begin();
    easyCam.pan(degrees);
    drawPointCloud();
    easyCam.end();
    fbo.end();
    
    // By default image is upside down and backwards. This corrects that
    fbo.draw(x+vWidth, y+vHeight, -vWidth, -vHeight);
};

void DepthFilter::drawPointCloud() {
	int w = 640;
	int h = 480;
	ofMesh mesh;
	mesh.setMode(OF_PRIMITIVE_POINTS);
	int step = 2;
	for(int y = 0; y < h; y += step) {
		for(int x = 0; x < w; x += step) {
			if(kinect.getDistanceAt(x, y) > 0) {
				mesh.addColor(kinect.getColorAt(x,y));
				mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
			}
		}
	}
	glPointSize(3);
	ofPushMatrix();
	// the projected points are 'upside down' and 'backwards'
	ofScale(1, -1, -1);
	ofTranslate(0, 0, -1000); // center the points a bit
	glEnable(GL_DEPTH_TEST);
	mesh.drawVertices();
	glDisable(GL_DEPTH_TEST);
	ofPopMatrix();
}

//--------------------------------------------------------------
string DepthFilter::loadDesc(string name){
    
    // Open the file, read in the text and return as a string
    ofFile file;
    
    file.open("../../../data/" + name + ".txt", ofFile::ReadOnly, false);
    ofBuffer buff = file.readToBuffer();
    
    return buff.getText();
    
}
