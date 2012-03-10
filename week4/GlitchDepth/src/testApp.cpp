#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);
    kinect.setDepthClipping(500,1000);
	kinect.setRegistration(true);// enable depth->video image calibration
	kinect.init();
	kinect.open();
	
	colorImg.allocate(kinect.width, kinect.height);
	grayImage.allocate(kinect.width, kinect.height);
	
	ofSetFrameRate(60);
    
	angle = 17;
	kinect.setCameraTiltAngle(angle);
	
	// start from the front
	bDrawPointCloud = false;
    
    curFrame.allocate(kinect.width, kinect.height, OF_IMAGE_COLOR);
}



void testApp::update() {
	ofBackground(100, 100, 100);
	
	kinect.update();
	if(kinect.isFrameNew()) {		
        
        
        ofPixels& depthPixels = kinect.getDepthPixelsRef();
        ofPixels& colorPixels = kinect.getPixelsRef();

        for (int x = 0; x < 640; x++) {
            for (int y = 0; y < 480; y++) {
                int loc = x + y*640;
                
                ofColor color = colorPixels.getColor(x, y);
                ofColor depth = depthPixels.getColor(x, y);
                
                if(depth.getBrightness() > mouseX){
                    curFrame.setColor(x, y, ofRandom(0,255));
                }else{
                    curFrame.setColor(x, y, color);
                }
                
            }
        }
	}
    curFrame.update();
}



void testApp::draw() {
	
	ofSetColor(255, 255, 255);

    curFrame.draw(0,0,640,480);//modified image
    kinect.drawDepth(0, 480, 400, 300);//depth
    kinect.draw(640, 0, 400, 300);//rgb
	
}



void testApp::exit() {
	kinect.setCameraTiltAngle(17); // zero the tilt on exit
	kinect.close();
}


void testApp::keyPressed (int key) {
	switch (key) {
		case ' ':
			bThreshWithOpenCV = !bThreshWithOpenCV;
			break;
			
		case'p':
			bDrawPointCloud = !bDrawPointCloud;
			break;
			
		case '>':
		case '.':
			farThreshold ++;
			if (farThreshold > 255) farThreshold = 255;
			break;
			
		case '<':
		case ',':
			farThreshold --;
			if (farThreshold < 0) farThreshold = 0;
			break;
			
		case '+':
		case '=':
			nearThreshold ++;
			if (nearThreshold > 255) nearThreshold = 255;
			break;
			
		case '-':
			nearThreshold --;
			if (nearThreshold < 0) nearThreshold = 0;
			break;
			
		case 'w':
			kinect.enableDepthNearValueWhite(!kinect.isDepthNearValueWhite());
			break;
			
		case 'o':
			kinect.setCameraTiltAngle(angle); // go back to prev tilt
			kinect.open();
			break;
			
		case 'c':
			kinect.setCameraTiltAngle(23); // zero the tilt
			kinect.close();
			break;
			
		case OF_KEY_UP:
			angle++;
			if(angle>30) angle=30;
			kinect.setCameraTiltAngle(angle);
			break;
			
		case OF_KEY_DOWN:
			angle--;
			if(angle<-30) angle=-30;
			kinect.setCameraTiltAngle(angle);
			break;
	}
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{}
