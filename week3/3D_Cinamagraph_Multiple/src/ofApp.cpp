#include "ofApp.h"

void ofApp::setup() {
	ofSetVerticalSync(true);
    ofSetFrameRate(24);
    
    maxImages = 30;
    imageIndex = 0;
    sceneIndex = 2;
    explode = false;
    switchtoDestImage = false;
    
    image = new ofImage[maxImages];   
    imageDest = new ofImage[maxImages];    
    
    for(int i=0; i<maxImages; i++){
        image[i].loadImage("2out"+ofToString(imageIndex)+".tiff");
        imageIndex++;
    }
    
    
    mesh= new ofMesh[maxImages];
    for(int i=0; i<maxImages; i++){
        
        mesh[i].setMode(OF_PRIMITIVE_POINTS);
        
        for(int y = 0; y < image[i].getHeight(); y++) {
            for(int x = 0; x < image[i].getWidth(); x++) {
                cur = image[i].getColor(x, y);
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
	glPointSize(1);
    
}

void ofApp::update() {

    if(!explode){
        imageIndex = (imageIndex+1) % maxImages;
    }else{
        imageIndex = 0;
    }

        if(ofGetKeyPressed('1')) {
            switchtoDestImage = false;
            explode=true;
            ofSeedRandom(0);
            for(int j = 0; j < mesh[imageIndex].getNumVertices(); j++) {
                ofVec3f point = mesh[imageIndex].getVertex(j);
                point*=1.001;
                point+=ofVec3f(ofRandomf(), ofRandomf(), ofRandomf());
                mesh[imageIndex].setVertex(j, point);
            }
        }
    
        if(ofGetKeyPressed('2')) {
            for(int i = 0; i< meshDest[imageIndex].getNumVertices(); i++){
                ofVec3f refpoint = meshDest[imageIndex].getVertex(i);
                ofVec3f point = mesh[imageIndex].getVertex(i);
                float increment=1-.2;
                float lerpX = ofLerp(refpoint.x, point.x, increment);
                float lerpY = ofLerp(refpoint.y, point.y, increment);
                float lerpZ = ofLerp(refpoint.z, point.z, increment);
                ofVec3f move(lerpX, lerpY, lerpZ);
                ofColor cur = meshDest->getColor(i).lerp(mesh->getColor(i), increment);
                mesh[imageIndex].setColor(i, cur);
                mesh[imageIndex].setVertex(i, move);
            }
        }
        

}

void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	ofScale(1, -1, 1); // make y point down
    if(!switchtoDestImage){
        mesh[imageIndex].draw();
    }else{
        meshDest[imageIndex].draw();
    }
	cam.end();
    
    //image[imageIndex].draw(0,0);
}


void ofApp::keyReleased(int key){
    
    if(key == '1'){
        if(sceneIndex<7){
            sceneIndex++;
        }else{
            sceneIndex = 2;
        }
        loadNewReference();
    }
    if(key == '2'){
        explode = false;
        switchtoDestImage = true;
    }
}


void ofApp::loadNewReference(){
    ///out << "scene: " << sceneIndex << endl;
    //    sceneIndexText = ofToString(sceneIndex) + "out"+ofToString(imageIndex)+".tiff";
    //cout << "file: " << sceneIndexText << endl;
    
    for(int i=0; i<maxImages; i++){
        imageDest[i].loadImage(ofToString(sceneIndex)+"out"+ofToString(imageIndex)+".tiff");
        imageIndex++;
    }
    
    meshDest= new ofMesh[maxImages];
    for(int i=0; i<maxImages; i++){
        
        meshDest[i].setMode(OF_PRIMITIVE_POINTS);
        meshDest[i].clear();
        
        for(int y = 0; y < imageDest[i].getHeight(); y++) {
            for(int x = 0; x < imageDest[i].getWidth(); x++) {
                curDest = imageDest[i].getColor(x, y);
                if(curDest.a > 0) {
                    // the alpha value encodes depth, let's remap it to a good depth range
                    float z = ofMap(curDest.a, 0, 255, -480, 480);
                    curDest.a = 255;
                    meshDest[i].addColor(curDest);
                    ofVec3f pos(x - imageDest[i].getWidth() / 2, y - imageDest[i].getHeight() / 2, z);
                    meshDest[i].addVertex(pos);
                }
            }
        }
        printf("save reference point data\n");
    }
    
}