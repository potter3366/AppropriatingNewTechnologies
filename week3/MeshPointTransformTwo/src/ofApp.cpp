#include "ofApp.h"

void ofApp::setup() {
	ofSetVerticalSync(true);
	img1.loadImage("linzer1.png");
    img2.loadImage("linzer3.png");
    
	mesh.setMode(OF_PRIMITIVE_POINTS);
	for(int y = 0; y < img1.getHeight(); y++) {
		for(int x = 0; x < img1.getWidth(); x++) {
            cur1 = img1.getColor(x, y);
			if(cur1.a > 0) {
				// the alpha value encodes depth, let's remap it to a good depth range
				float z = ofMap(cur1.a, 0, 255, -480, 480);
				cur1.a = 255;
				mesh.addColor(cur1);
				ofVec3f pos(x - img1.getWidth() / 2, y - img1.getHeight() / 2, z);
				mesh.addVertex(pos);
			}
		}
	}
    referenceMesh.setMode(OF_PRIMITIVE_POINTS);
	for(int y = 0; y < img2.getHeight(); y++) {
		for(int x = 0; x < img2.getWidth(); x++) {
            cur2 = img2.getColor(x, y);
			if(cur2.a > 0) {
				// the alpha value encodes depth, let's remap it to a good depth range
				float z = ofMap(cur2.a, 0, 255, -480, 480);
				cur2.a = 255;
				referenceMesh.addColor(cur2);
				ofVec3f pos(x - img2.getWidth() / 2, y - img2.getHeight() / 2, z);
				referenceMesh.addVertex(pos);
			}
		}
	}
	
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
            float increment=1-.3;
            float lerpX = ofLerp(refpoint.x, point.x, increment);
            float lerpY = ofLerp(refpoint.y, point.y, increment);
            float lerpZ = ofLerp(refpoint.z, point.z, increment);
            ofVec3f move(lerpX, lerpY, lerpZ);
            ofColor cur = referenceMesh.getColor(i).lerp(mesh.getColor(i), increment);
            mesh.setColor(i, cur);
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