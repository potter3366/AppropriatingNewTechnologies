#include "ofApp.h"

void ofApp::setup() {
	ofSetVerticalSync(true);
    ofSetFrameRate(30);
    
    maxImages = 49;
    imageIndex = 0;
    
    image = new ofImage[maxImages];    
    for(int i=0; i<maxImages; i++){
        image[i].loadImage("out"+ofToString(imageIndex)+".tiff");
        imageIndex++;
    }

    mesh= new ofMesh[maxImages];
    for(int i=0; i<maxImages; i++){
        
        mesh[i].setMode(OF_PRIMITIVE_POINTS);
        
        for(int y = 0; y < image[i].getHeight(); y++) {
            for(int x = 0; x < image[i].getWidth(); x++) {
                ofColor cur = image[i].getColor(x, y);
                if(cur.a > 0) {
                    // the alpha value encodes depth, let's remap it to a good depth range
                    float z = ofMap(cur.a, 0, 255, -480, 480);
                    cur.a = 255;
                    mesh[i].addColor(cur);
                    ofVec3f pos(x - image[i].getWidth() / 2, y - image[i].getHeight() / 2, z);
                    mesh[i].addVertex(pos);
                }
            }
        }

    }
    
    
	// even points can overlap with each other, let's avoid that
	glEnable(GL_DEPTH_TEST);
	
	// make the points bigger, otherwise it's hard to see them
	glPointSize(4);
}

void ofApp::update() {
    imageIndex = (imageIndex+1) % maxImages;

}

void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	ofScale(1, -1, 1); // make y point down
	mesh[imageIndex].draw();
	cam.end();
    
    //image[imageIndex].draw(0,0);
}