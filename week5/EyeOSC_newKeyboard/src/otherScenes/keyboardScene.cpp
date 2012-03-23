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
    
	gothamUltra.loadFont("fonts/HandTIMES.ttf", 20);
	gothamUltraKeys.loadFont("fonts/HandTIMES.ttf", 48);
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
    
    
    bounds = new ofRectangle[26];
    counter = new int[26];
    for(int i; i< 26; i++){
        counter[i] = 0;
    }
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
    scaleNum0 = 0.4;
    scaleNum1 = 0.4;
}




void keyboardScene::update(float mouseX, float mouseY){
	mx = mouseX;
	my = mouseY;
	
    

	
}	

//--------------------------------------------------------------
void keyboardScene::draw(){
    mouseX = mx;
    mouseY = my;
    
    offset = ofDist(mouseX, ofGetWindowWidth()/2, mouseY, ofGetWindowHeight()/2);
    cout << "offset" << offset<<endl;
    
    
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
//    ofRectangle bounds0 = gothamUltraKeys.getStringBoundingBox(buttons[0], 0, 0);
//    ofTranslate(10, ofGetWindowHeight()-100, 0);    
//    if(mouseX > 10-bounds0.width/2 && mouseX < 10+bounds0.width/2 && mouseY> ofGetWindowHeight()-100-bounds0.height/2+bounds0.y/2 && mouseY< ofGetWindowHeight()-100+bounds0.height/2+bounds0.y/2){
//        ofScale(scaleNum, scaleNum);
//        scaleNum+=0.1;
//        if(scaleNum >= 1.0){
//            scaleNum=1.0;
//        }
//    }else{
//        ofScale(scaleNum, scaleNum);
//        scaleNum-=0.2;
//        if(scaleNum <= 0.4){
//            scaleNum=0.4;
//        }
//    }
//    ofSetColor(255, 0, 0);
//    ofRect(bounds0.x, bounds0.y+bounds0.height/2, bounds0.width, bounds0.height);
//    ofSetColor(255);
//        gothamUltraKeys.drawString(buttons[0], -bounds0.width/2, bounds0.height/2+bounds0.y/2);
//    ofPopStyle();
//    ofPopMatrix();
    
//    ofPushMatrix();
//    ofPushStyle();
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofRectangle bounds0 = gothamUltraKeys.getStringBoundingBox(buttons[0], 0, 0);
//    ofTranslate(30, ofGetWindowHeight()-100, 0);    
//    if(mouseX > 30-bounds0.width/2 && mouseX < 30+bounds0.width/2 && mouseY> ofGetWindowHeight()-100-bounds0.height/2+bounds0.y/2 && mouseY< ofGetWindowHeight()-100+bounds0.height/2+bounds0.y/2){
//        ofScale(scaleNum0, scaleNum0);
//        scaleNum0+=0.1;
//        if(scaleNum0 >= 1.0){
//            scaleNum0=1.0;
//        }
//    }else{
//        ofScale(scaleNum0, scaleNum0);
//        scaleNum0-=0.2;
//        if(scaleNum0 <= 0.4){
//            scaleNum0=0.4;
//        }
//    }
//    ofSetColor(255, 0, 0);
//    ofRect(bounds0.x, bounds0.y+bounds0.height/2, bounds0.width, bounds0.height);
//    ofSetColor(255);
//        gothamUltraKeys.drawString(buttons[0], -bounds0.width/2, bounds0.height/2+bounds0.y/2);
//    ofPopStyle();
//    ofPopMatrix();
//
//    
//    
//    ofPushMatrix();
//    ofPushStyle();
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofRectangle bounds1 = gothamUltraKeys.getStringBoundingBox(buttons[1], 0, 0);
//    ofTranslate(86, ofGetWindowHeight()-100, 0);    
//    if(mouseX > 86-bounds1.width/2 && mouseX < 86+bounds1.width/2 && mouseY> ofGetWindowHeight()-100-bounds1.height/2+bounds1.y/2 && mouseY< ofGetWindowHeight()-100+bounds1.height/2+bounds1.y/2){
//        ofScale(scaleNum1, scaleNum1);
//        scaleNum1+=0.1;
//        if(scaleNum1 >= 1.0){
//            scaleNum1=1.0;
//        }
//    }else{
//        ofScale(scaleNum1, scaleNum1);
//        scaleNum1-=0.2;
//        if(scaleNum1 <= 0.4){
//            scaleNum1=0.4;
//        }
//    }
//    ofSetColor(255, 0, 0);
//    ofRect(bounds1.x, bounds1.y+bounds1.height/2, bounds1.width, bounds1.height);
//    ofSetColor(255);
//    gothamUltraKeys.drawString(buttons[1], -bounds1.width/2, bounds1.height/2+bounds1.y/2);
//    ofPopStyle();
//    ofPopMatrix();
    

    

//    ofPushMatrix();
//    ofPushStyle();
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofTranslate(0, 500, 0);   
//    
//    int posX = 0;
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
//        //cout << "w: " << bounds[i].width << " x: " << posX << endl;  
//        cout << enlarge << endl;
//        
//        posX+= bounds[i].width/2;
//        
//        ofSetColor(255, 0, 0);
//        ofRect(posX, bounds[i].y+bounds[i].height/2, bounds[i].width, bounds[i].height);
//        
//        ofSetColor(255);
//        gothamUltraKeys.drawString(buttons[i], posX-bounds[i].width/2, bounds[i].height/2+bounds[i].y/2);
//
//        posX += bounds[i].width/2 + padding;
//
//    }
//    ofPopStyle();
//    ofPopMatrix();
    
    
    
    
    indexOfSel = -1;
    int padding = 5;

    ofPushMatrix();
    ofPushStyle();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofTranslate(0, ofGetWindowHeight()-150, 0);   
    
    posX = 15;


    
    for (int i=0; i<26; i++) {
        bounds[i] = gothamUltraKeys.getStringBoundingBox(buttons[i], 0, 0);

        posX+= bounds[i].width/2;
        
//        ofSetColor(255, 0, 0);
//        ofRect(posX, bounds[i].y+bounds[i].height/2, bounds[i].width, bounds[i].height);


        if(rolloverIdentifier(mouseX, mouseY, posX)) {
            indexOfSel = i;
            //break;
        }
        if(i == indexOfSel){
            ofSetColor(0);
            counter[i]++;
            ofPushMatrix();
            ofTranslate(0, 0);
        }else{
            ofSetColor(255);
            counter[i]=0;
            ofPushMatrix();
            ofTranslate(0, 10);
        }
        if(counter[i] > 40){
            layedoutmessage += buttons[i];
            counter[i]=0;
        }
        gothamUltraKeys.drawString(buttons[i], posX-bounds[i].width/2, bounds[i].height/2+bounds[i].y/2);
        ofPopMatrix();
        //cout << indexOfSel << endl;
        posX += bounds[i].width/2 + padding;
    }
    ofPopStyle();
    ofPopMatrix();


    for(int i; i<26; i++){
        
    }
    
    
    
	ofFill();
	ofSetColor(0,0,0);
	ofRect(0,0,ofGetWidth(), 200);
	
	
	ofSetColor(255,255,255);

    
	
	
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


bool keyboardScene::rolloverIdentifier(int mx, int my, int _x){
    mx = mouseX;
    my = mouseY;
    _x = posX;
    int x =_x;
    if(mx > x-44/2-5 && mx < x+44/2+5 && my > ofGetWindowHeight()-150-80/2-5 && my < ofGetWindowHeight()-150+5){
        return true;
    }
    return false;
}
