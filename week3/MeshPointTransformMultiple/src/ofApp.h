#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void loadNewReference();
    
	ofEasyCam cam;
	ofMesh mesh;
    
    ofMesh referenceMesh;
    bool referenceSwitch;
    
    float distort;
    ofImage img1;
    ofImage img2;
    ofImage img3;
    ofColor cur1;
    ofColor cur2;
    ofColor cur3;
    
};
