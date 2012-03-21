/*
 *  keyboardScene.cpp
 *  openFrameworks
 *
 *  Created by andrea bradshaw on 4/10/2010.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "keyboardScene.h"

//switch to gui
extern  int buttonCount; 

//--------------------------------------------------------------
void keyboardScene::setup(){
    
	gothamUltra.loadFont("fonts/ProFontWindows.ttf", 60);
	gothamUltraKeys.loadFont("fonts/ProFontWindows.ttf", 60);
	carriageReturnCounter = 0;

	ofBackground(255, 255, 255);
	
    buttons = new string[26];
    buttons[0] = "A";
    buttons[1] = "B";
    buttons[2] = "C";
    buttons[3] = "D";
    buttons[4] = "E";
    buttons[5] = "F";
    buttons[6] = "G";
    buttons[7] = "H";
    buttons[8] = "I";
    buttons[9] = "J";
    buttons[10] = "K";
    buttons[11] = "L";
    buttons[12] = "M";
    buttons[13] = "N";
    buttons[14] = "O";
    buttons[15] = "P";
    buttons[16] = "Q";
    buttons[17] = "R";
    buttons[18] = "S";
    buttons[19] = "T";
    buttons[20] = "U";
    buttons[21] = "V";
    buttons[22] = "W";
    buttons[23] = "X";
    buttons[24] = "Y";
    buttons[25] = "Z";
    
    test = "I"; //ABCDEFGHIJKLMNOPQRSTUVWXYZ
    scaleNum = 0.4;
    
    bounds = new ofRectangle[26];
    enlarge = false;
//	{
//		"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
//		"K", "L", "M", "N", "O", "P", "Q", "R", "S", 
//		"T", "U", "V", "W", "X", "Y", "Z"
//	};

	
//	float xadd2 = 0;
//	float yadd2 = 200;
//	
//	
//	float xStart  = 5;
//	float yStart  = ofGetWindowHeight()-400;
//	float bWidth  = 47;
//	float bHeight = 100;
//	
//	for (int i = 0; i < 26; i++){
//		buttonTrigger nButton;
//		nButton.setup(buttons[i], xStart + xadd2, yStart + yadd2, bWidth, bHeight);
//		nButton.setMaxCounter(buttonCount);
//		nButton.setRetrigger(false);
//		letterButtons.push_back(nButton);
//		
//		xStart += 49;
//		
//	}
//
//	for (int i = 0; i < letterButtons.size(); i++){
//		letterButtons[i].setDisplayFont(&gothamUltraSmall);
//
//	}
	
	mx = 0.0;
	my = 0.0; 
	mouseX = 0.0;
    mouseY = 0.0;

}




void keyboardScene::update(float mouseX, float mouseY){
	mx = mouseX;
	my = mouseY;
	

    

	
}	

//--------------------------------------------------------------
void keyboardScene::draw(){
    mouseX = ofGetMouseX();
    mouseY = ofGetMouseY();
    
    

    
    
	ofPushStyle();	
	
//    ofPushMatrix();
//    string scaleA = "SCALE ALIASED";
//    bounds = verdana14A.getStringBoundingBox(scaleA, 0, 0);
//    
//    ofTranslate(500 + bounds.width/2, 530 + bounds.height / 2, 0);
//    ofScale(2.0 + cos(ofGetElapsedTimef()), 2.0 + cos(ofGetElapsedTimef()), 1.0);
//    
//    verdana14A.drawString(scaleA, -bounds.width/2, bounds.height/2 );
//	ofPopMatrix();
    

    
    
//    ofPushMatrix();
//    ofPushStyle();
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofRectangle bounds = gothamUltraKeys.getStringBoundingBox(buttons[1], 0, 0);
//    ofTranslate(500, 500, 0);    
////    if(mouseX > 500-bounds.width/2 && mouseX < 500+bounds.width/2 && mouseY> 500-bounds.height/2+bounds.y/2 && mouseY< 500+bounds.height/2+bounds.y/2){
////        ofScale(scaleNum, scaleNum);
////        scaleNum+=0.1;
////        if(scaleNum >= 1.0){
////            scaleNum=1.0;
////        }
////    }else{
////        ofScale(scaleNum, scaleNum);
////        scaleNum-=0.2;
////        if(scaleNum <= 0.4){
////            scaleNum=0.4;
////        }
////    }
//    
//
//    ofSetColor(255, 0, 0);
//    ofRect(bounds.x, bounds.y+bounds.height/2, bounds.width, bounds.height);
////    for(int i=0; i<26; i++){
//    ofSetColor(255);
//        gothamUltraKeys.drawString(buttons[1], -bounds.width/2, bounds.height/2+bounds.y/2);
////    }
//    ofPopStyle();
//    ofPopMatrix();
    

    

//    ofPushMatrix();
//    ofPushStyle();
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofTranslate(0, 500, 0);   
//    
//    int fontX = 0;
//    int padding = 5;
//
//    for (int i=0; i<26; i++) {
//        bounds[i] = gothamUltraKeys.getStringBoundingBox(buttons[i], 0, 0);
//        
//        if(mouseX > 0-bounds[i].width/2 && mouseX < 0+bounds[i].width/2 && mouseY > 500-bounds[i].height/2 && mouseY <  500+bounds[i].height/2){
//            ofScale(scaleNum, scaleNum);
//            scaleNum+=0.004;
//            if(scaleNum >= 1.0){
//                scaleNum=1.0;
//            }
//        }else{
//            ofScale(scaleNum, scaleNum);
//            scaleNum-=0.01;
//            if(scaleNum <= 0.4){
//                scaleNum=0.4;
//            }
//        }
//        
//        //cout << "w: " << bounds[i].width << " x: " << fontX << endl;  
//        cout << enlarge << endl;
//        
//        fontX+= bounds[i].width/2;
//        
//        ofSetColor(255, 0, 0);
//        ofRect(fontX, bounds[i].y+bounds[i].height/2, bounds[i].width, bounds[i].height);
//        
//        ofSetColor(255);
//        gothamUltraKeys.drawString(buttons[i], fontX-bounds[i].width/2, bounds[i].height/2+bounds[i].y/2);
//
//        fontX += bounds[i].width/2 + padding;
//
//    }
//    ofPopStyle();
//    ofPopMatrix();
    
    

    
    
    ofPushMatrix();
    ofPushStyle();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofTranslate(0, 500, 0);   
    
    int fontX = 0;
    int padding = 5;

    for (int i=0; i<26; i++) {
        bounds[i] = gothamUltraKeys.getStringBoundingBox(buttons[i], 0, 0);
        
        fontX+= bounds[i].width/2;
        
        ofSetColor(255, 0, 0);
        ofRect(fontX, bounds[i].y+bounds[i].height/2, bounds[i].width, bounds[i].height);
        
        ofSetColor(255);
        gothamUltraKeys.drawString(buttons[i], fontX-bounds[i].width/2, bounds[i].height/2+bounds[i].y/2);

        fontX += bounds[i].width/2 + padding;

    }
    ofPopStyle();
    ofPopMatrix();

    

    
    
    
	ofFill();
	ofSetColor(0,0,0);
	ofRect(0,0,ofGetWidth(), 200);
	
	
	ofSetColor(255,255,255);

    
	layedoutmessage = "";
	
	if (displayMessage.size() > 0){
		int count = 0;
		for (int i = 0; i < displayMessage.size(); i++){
			layedoutmessage.push_back(displayMessage[i]);
			count++;
			if (count >  58){
				layedoutmessage += "-\n";
				count = 0;
			}
		}
	}
	

	gothamUltra.drawString(layedoutmessage, 30, 50);
	ofDrawBitmapString(layedoutmessage, mx, my);
    
    
	
	vector <string> strings = ofSplitString(layedoutmessage, "\n");
	string subMessage = layedoutmessage;
	if(strings.size() > 1){
		subMessage = strings[strings.size()-1];
	}
	float xx = gothamUltra.getStringBoundingBox(subMessage + ".", 30, 50).x + gothamUltra.getStringBoundingBox(subMessage+ ".", 30, 50).width;
	float yy = gothamUltra.getStringBoundingBox(layedoutmessage + ".", 30, 50).y + gothamUltra.getStringBoundingBox(layedoutmessage+ ".", 30, 50).height;
	
	ofSetColor(127, 127, 127);
	ofRect(xx, yy, 10,3);
	
	ofPopStyle();
	
	//drawCursor();
}

void keyboardScene::rollover(int mx, int my, int x, int width){
    if(mx > x-width && mx < x+width && my > 500){
        enlarge = true;
    }else{
        enlarge = false;
    }
}
