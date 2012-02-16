#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	ofEasyCam cam;
	ofMesh mesh;
    
    ofMesh referenceMesh;
    
    float distort;
    ofImage img;
};
