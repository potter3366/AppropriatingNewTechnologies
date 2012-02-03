#include "testApp.h"

extern "C" {
#include "macGlutfix.h"
}

//--------------------------------------------------------------
void testApp::setup(){

	finder.setup("haarcascade_frontalface_default.xml");
	//CGContextRef cgctx = NULL;
	//ofSetVerticalSync(true);
	//tex.allocate(300,300, GL_RGBA);
	image.allocate(300, 300, OF_IMAGE_COLOR);
	//pixels.allocate(300, 300, OF_IMAGE_COLOR);
	
	ofSetFrameRate(30);
    face.loadImage("face.png");
    ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void testApp::update(){
	
	int w = 300;
	int h = 300;
	
	unsigned char * data = pixelsBelowWindow(ofGetWindowPositionX(),ofGetWindowPositionY(),w,h);
	
	// now, let's get the R and B data swapped, so that it's all OK:
	for (int i = 0; i < w*h; i++){
		
		unsigned char a = data[i*4]; // mem A  
		
		data[i*4]   = data[i*4+1];   
		data[i*4+1] = data[i*4+2];   
		data[i*4+2] = data[i*4+3];   
		data[i*4+3] = a; 
	}
	
	
	if (data!= NULL) {
		//tex.loadData(data, 300, 300, GL_RGBA);
		//tex.readToPixels(pixels);
		//image = pixels;
		image.setFromPixels(data, 300, 300, OF_IMAGE_COLOR_ALPHA, true);
		image.setImageType(OF_IMAGE_COLOR);
		image.update();
		finder.findHaarObjects(image.getPixelsRef());
        imageCopy = image;
        imageCopy.update();
        
        
//        //----code to make face green--utilizing full image
//        for (int x = 0; x < w; x++) {
//            for (int y = 0; y < h; y++) {
//                int index = x + y * w;
//                
//                for(int i = 0; i < finder.blobs.size(); i++) {
//                    if(x > finder.blobs[i].boundingRect.x && x < finder.blobs[i].boundingRect.x + finder.blobs[i].boundingRect.width && y > finder.blobs[i].boundingRect.y && y < finder.blobs[i].boundingRect.y + finder.blobs[i].boundingRect.height){
//                        // this pixel is inside of a blob
//                        r = data[index*4];
//                        g = data[index*4+1];
//                        b = data[index*4+2];
//                        a = data[index*4+3];
//                        
//                        data[index*4]   = g;   
//                        data[index*4+1] = r;   
//                        data[index*4+2] = b;
//                        data[index*4+3] = a;
//    
//                    }
//                       
//                       //finder.blobs[i].boundingRect.x > x && finder.blobs[i].boundingRect.x + finder.blobs[i].boundingRect.width <
//                }
//            }
//        }
        
        imageCopy.setFromPixels(data, 300, 300, OF_IMAGE_COLOR_ALPHA, true);
		imageCopy.setImageType(OF_IMAGE_COLOR);
		imageCopy.update();
	}
	//cout << imageBelowWindow()[0] << endl;
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	//image.draw(0,0, ofGetWidth(), ofGetHeight());
    imageCopy.draw(0,0);
    
    for(int i = 0; i < finder.blobs.size(); i++) {
        ofPushStyle();
        ofFill();//make color fill
        //ofSetColor(255, 0, 0);//make red
        face.draw(finder.blobs[i].boundingRect.x-13, finder.blobs[i].boundingRect.y-23, finder.blobs[i].boundingRect.width+35, finder.blobs[i].boundingRect.height+30);
		//ofRect(finder.blobs[i].boundingRect);
        ofPopStyle();
    }
    
    
    
    
    
    
//    for(int j=0; j<ofGetWidth();j++){
//        for(int k=0; k<ofGetHeight(); k++){
//        ofFill();
//        ofSetColor(r, g, b);
//        ofRect(j*20, k*20, 10, 10);
//        }
//    }
	
    
//    unsigned char* pixels = imageCopy.getPixels();
//    
//    for(int i = 0; i < imageCopy.getHeight(); i++){
//        for(int j = 0; j < imageCopy.getWidth(); j++){
//
//            int loc = i + j * imageCopy.getWidth();
//            ofColor color ;
//            color.r = pixels[loc] ; //red pixel
//            color.g = pixels[loc+1] ; //blue pixel
//            color.b = pixels[loc+2] ; //green pixel
//            color.r =0;
//            imageCopy.draw(150,150);//copy
//              
////                ofColor cur = imageCopy.getColor(x, y);
//                
////                unsigned char red = pixels[(y * w + x) * 4 + 0];
////                unsigned char green = pixels[(y * w + x) * 4 + 1];
////                unsigned char blue = pixels[(y * w + x) * 4 + 2];
////                unsigned char alpha = pixels[(y * w + x) * 4 + 3];
//            }
//    }
//    
    
//    unsigned char* pixels = imageCopy.getPixels();
//    for (int x = 0; x<imageCopy.getHeight(); x++) {
//        for (int y = 0; y<imageCopy.getWidth(); y++) {
//            ofColor cur = imageCopy.getColor(x, y);
//            
//            
//  
//            
//            //calculate the amount to cange brightness based on proximity to mouse
//            float maxdist = 100;
//            float d = ofDist(x,y,mouseX, mouseY);
//            float adjustbrightness = (maxdist-d)/maxdist;
//            cur *= adjustbrightness;
//            
//            imageCopy.setColor(x, y, cur);
//        }
//    }
//    imageCopy.update();
//    imageCopy.draw(0, 0);
    
    
    //---------------------------------
    
    
//	ofNoFill();
//	
//	//for each face "blob" we found, draw a rectangle around the face
//    //#2
//	for(int i = 0; i < finder.blobs.size(); i++) {
//        
//        unsigned char* pixels = imageCopy.getPixels();
//        for (int x = 0; x<imageCopy.getHeight(); x++) {
//            for (int y = 0; y<imageCopy.getWidth(); y++) {
//                float varrad = finder.blobs[i].boundingRect.width/1.8;
//                ofColor cur = imageCopy.getColor(x+varrad, y+varrad);
//                
//                
//                //calculate the amount to cange brightness based on proximity to mouse
//                float maxdist = finder.blobs[i].boundingRect.width/1.8;
//                float d = ofDist(x,y,finder.blobs[i].boundingRect.x,finder.blobs[i].boundingRect.y);
//                float adjustbrightness = (maxdist-d)/maxdist;
//                cur *= adjustbrightness;
//                
//                
//                imageCopy.setColor(x, y, cur);
//            }
//        }
//        imageCopy.update();
//        imageCopy.draw(0, 0);

//    ofNoFill();
	
	//for each face "blob" we found, draw a rectangle around the face
    //#2
//	for(int i = 0; i < finder.blobs.size(); i++) {
        
        /*unsigned char* pixels = imageCopy.getPixels();
        for (int x = finder.blobs[i].boundingRect.x; x<finder.blobs[i].boundingRect.width; x++) {
            for (int y = finder.blobs[i].boundingRect.y; y<finder.blobs[i].boundingRect.height; y++) {

                int w = finder.blobs[i].boundingRect.width;
                unsigned char red = pixels[(y * w + x) * 3 + 0];
                unsigned char green = pixels[(y * w + x) * 3 + 1];
                unsigned char blue = pixels[(y * w + x) * 3 + 2];
                
                       
                imageCopy.setColor(x, y, ofColor(red, green, blue));
            }
        }
        imageCopy.update();
        imageCopy.draw(10, 10);*/
        
        
//        ofPushStyle();
//        ofFill();//make color fill
//        ofSetColor(255, 0, 0);//make red
//		ofRect(finder.blobs[i].boundingRect);
//        ofPopStyle();
    
//	}
	
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