#include "ofApp.h"

void ofApp::setup() {
	ofSetVerticalSync(true);
	img.loadImage("linzer1.png");

	mesh.setMode(OF_PRIMITIVE_POINTS);
	for(int y = 0; y < img.getHeight(); y++) {
		for(int x = 0; x < img.getWidth(); x++) {
			ofColor cur = img.getColor(x, y);
			if(cur.a > 0) {
				// the alpha value encodes depth, let's remap it to a good depth range
				float z = ofMap(cur.a, 0, 255, -480, 480);
				cur.a = 255;
				mesh.addColor(cur);
				ofVec3f pos(x - img.getWidth() / 2, y - img.getHeight() / 2, z);
				mesh.addVertex(pos);
			}
		}
	}
    referenceMesh = mesh;
	
	// even points can overlap with each other, let's avoid that
	glEnable(GL_DEPTH_TEST);
	
	// make the points bigger, otherwise it's hard to see them
	glPointSize(1);
    
    
}

void ofApp::update() {
    if(ofGetKeyPressed('1')) {
        ofSeedRandom(0);
        for(int i = 0; i < mesh.getNumVertices(); i++) {
            ofVec3f point = mesh.getVertex(i);
            point*=1.001;
            point+=ofVec3f(ofRandomf(), ofRandomf(), ofRandomf());
            mesh.setVertex(i, point);
        }
    }
    if(ofGetKeyPressed('2')) {
        for(int i = 0; i< referenceMesh.getNumVertices(); i++){
            ofVec3f refpoint = referenceMesh.getVertex(i);
            ofVec3f point = mesh.getVertex(i);
            float increment=1-.2;
            float lerpX = ofLerp(refpoint.x, point.x, increment);
            float lerpY = ofLerp(refpoint.y, point.y, increment);
            float lerpZ = ofLerp(refpoint.z, point.z, increment);
            ofVec3f move(lerpX, lerpY, lerpZ);
            mesh.setVertex(i, move);
        }
    }

}

void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	ofScale(1, -1, 1); // make y point down
	mesh.draw();
	cam.end();
}