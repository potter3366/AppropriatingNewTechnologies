#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        void display(int _x);
        void displayLetter(int mx, int my, float _x, ofColor _color);
        void displayFont(string _buttons, int _x, ofColor _color);
        void rollover(int mx, int my, float _x);
        bool rolloverIdentifier(int mx, int my, int _x);
        int mouseX, mouseY;
        int x, y, width;
        bool enlarge;
        float scaler;
        int padding;
    
        ofTrueTypeFont  fontKeys;
        string * buttons;
        int offset;
};
