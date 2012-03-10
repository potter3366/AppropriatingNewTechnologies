#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(24);
    camWidth = 640;
	camHeight = 480;
	
    scale = 4;
    cols = ofGetWindowWidth()/scale;
    rows = ofGetWindowHeight()/scale;
    
	video.setVerbose(true);
	video.initGrabber(camWidth,camHeight);
    curFrame.allocate(camWidth, camHeight, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void testApp::update(){
    ofBackground(0, 0, 0);
	video.grabFrame();

    
	if (video.isFrameNew()){
        curFrame = video.getPixelsRef();
        
//        for(int i =0; i< rows; i++){
//            for(int j=0; j<cols; j++){
//                x = i*scale;
//                y = j*scale;
//                
//                curColor = curFrame.getColor(i, j);
//                ofFill();
//                ofSetColor(curColor);
//                ofRect(x,y,scale,scale);
//            }
//        }
        curFrame.update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
//    curFrame.draw(0, 0); //good glitch if turned on w/ code in update
    ofSeedRandom();
    for(int i =0; i< rows; i++){
        for(int j=0; j<cols; j++){
            x = i*scale;
            y = j*scale;
            curColor = curFrame.getColor(x, y);
            ofFill();
            ofSetColor(curColor);
            ofRect(x+ofRandom(-100,100),y+ofRandom(-100,100),scale,scale);
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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