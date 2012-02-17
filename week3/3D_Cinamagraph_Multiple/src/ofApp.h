#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void keyReleased(int key);
	void loadNewReference();
	
	ofEasyCam cam;
	ofMesh* mesh;
    ofImage* image;
    ofColor cur;
    
    ofMesh* meshDest;
    ofImage* imageDest;
    ofColor curDest;
    
    int maxImages;
    int imageIndex;
    int sceneIndex;
    string sceneIndexText;
    
    bool explode;
    bool switchtoDestImage;

};
