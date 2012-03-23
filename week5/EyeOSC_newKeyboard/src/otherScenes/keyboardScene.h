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
    void rollover(int mx, int my, int x, int width);
	
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
    bool enlarge;
    bool rolloverIdentifier(int mx, int my, int _x);
    int posX;
    int indexOfSel;
    float scaleNum0, scaleNum1;
    int *counter;
    int pointerSize;
private:
	void typedMessage(string msg);
	
    float offset;
};

