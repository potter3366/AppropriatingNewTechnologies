#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
	ofSetVerticalSync(true);
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
	
	cam.initGrabber(640, 480);
	
	destTracker.setup();

    //face tracking on source
    srcTracker.setup();
    srcimg.loadImage("trump2.jpg");
    srcTracker.update(toCv(srcimg));
    srcPosition = srcTracker.getPosition();
    srcScale = srcTracker.getScale();
    srcOrientation = srcTracker.getOrientation();
    srcRotationMatrix = srcTracker.getRotationMatrix();
    srcPoints = srcTracker.getImagePoints();

}

void testApp::update() {
    //face tracking on camera being update every second
	cam.update();
	if(cam.isFrameNew()) {
		destTracker.update(toCv(cam));
		position = destTracker.getPosition();
		scale = destTracker.getScale();
		orientation = destTracker.getOrientation();
		rotationMatrix = destTracker.getRotationMatrix();
	}
}

void testApp::draw() {
	ofSetColor(255);
    srcimg.draw(0,0);
    srcTracker.getObjectMesh().drawWireframe();
    //srcTracker.draw();
    
	cam.draw(0, 0, 128, 96);
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);

    if(destTracker.getFound()) {
        ofSetLineWidth(1);
        //tracker.draw();
        
        ofMesh camMesh = destTracker.getObjectMesh();
        camMesh.clearTexCoords();
        camMesh.addTexCoords(srcPoints);
        
        srcimg.getTextureReference().bind();
        ofSetupScreenOrtho(640, 480, OF_ORIENTATION_UNKNOWN, true, -1000, 1000);
        ofTranslate(srcPosition.x, srcPosition.y);
        applyMatrix(srcRotationMatrix);
        ofScale(srcScale,srcScale,srcScale);
        ofDrawAxis(scale);
        camMesh.draw();
        srcimg.getTextureReference().unbind();
    }

    
}

void testApp::keyPressed(int key) {
	if(key == 'r') {
		destTracker.reset();
	}
}