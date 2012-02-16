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
    ofImage img1;
    ofImage img2;
    ofColor cur1;
    ofColor cur2;
};
