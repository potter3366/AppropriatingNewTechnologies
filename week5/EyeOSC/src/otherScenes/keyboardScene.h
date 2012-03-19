/*
 *  drawingScene.h
 *  openFrameworks
 *
 *  Created by theo on 20/08/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "buttonStateManager.h"
#include "buttonState.h"

#include "buttonRect.h"
#include "buttonToggle.h"
#include "buttonTrigger.h"

#include "ofxXmlSettings.h"
#include "baseScene.h"

extern "C" {
#include "speak.h"
};


class keyboardScene : public baseScene{
	
public:
	
	void setup();
	void update(float mouseX, float mouseY);
	void draw();
	
	buttonTrigger	doneButton;

	
	vector <buttonTrigger> letterButtons;
	string * buttons;
    ofRectangle * bounds;
    string test;
    
	vector <string> letterButtons_lower;
	vector<string> triggeredMessageLog;
	vector<int> triggeredKeyCodes;
	//vector<string> message;
	vector<buttonToggle> actionButtons;
	string displayMessage;
	int carriageReturnCounter;
	
	ofTrueTypeFont  gothamUltra;
	ofTrueTypeFont  gothamUltraKeys;
    string layedoutmessage;
	
    float mouseX;
    float mouseY;
    float scaleNum;
    
private:
	void typedMessage(string msg);
	
};

