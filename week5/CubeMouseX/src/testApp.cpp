#include "testApp.h"


void testApp::setup(){
    ofSetFrameRate(30);
    mouseX=0;
    mouseY=0;
    
    x=100;
    y=100;
    width= ofGetWindowWidth()/30;
    enlarge=false;
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    scaler = 0;
    padding = 6;
    
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
    
    fontKeys.loadFont("fonts/ProFontWindows.ttf", 24);
}


void testApp::update(){
    mouseX = ofGetMouseX();
    mouseY = ofGetMouseY();
    
    offset = mouseX-ofGetWindowWidth()/2;
}


void testApp::draw(){
    int indexOfSel = -1;

    for(int i=0; i < 26; i++){
        int posXX;
        posXX = i*(width+padding);
        if(rolloverIdentifier(mouseX, mouseY, posXX)) {
            indexOfSel = i;
            //break;
        }
    }
    ofColor temp;
    if(mouseY> 70){
        if (scaler < 1) {
            scaler +=.1;
        }
    }else{
        scaler = 0;
    }
    float realWidth = width;
    float posX;
    for(int i=0; i < 26; i++){
        if(i < indexOfSel && indexOfSel != -1){
            temp = ofColor(0, 0, 255);
            posX = (width+padding)*i - (padding)*scaler;
        }
        else if(i > indexOfSel && indexOfSel != -1){
            temp = ofColor(0, 255, 0);
            posX = (width+padding)*i + (padding)*scaler;
        } else {
            temp = ofColor(255, 0, 0);
            posX = (width+padding) * i;
            
        }
        
//        width = ofMap(abs(posX - mouseX), 0, 100, 2, 1, true) * realWidth;//////kyle line
        
        //cout << indexOfSel<<" posX : "<<posX << endl;
        //display(posX);
        rollover(mouseX, mouseY, posX);
        displayLetter(mouseX, mouseY, posX, temp);
        displayFont(buttons[i], posX, temp);
    }
}


void testApp::keyPressed(int key){

}


void testApp::keyReleased(int key){

}


void testApp::mouseMoved(int x, int y ){

}


void testApp::mouseDragged(int x, int y, int button){

}


void testApp::mousePressed(int x, int y, int button){

}


void testApp::mouseReleased(int x, int y, int button){

}


void testApp::windowResized(int w, int h){

}


void testApp::gotMessage(ofMessage msg){

}


void testApp::dragEvent(ofDragInfo dragInfo){ 
}


void testApp::display(int _x){
    x= _x;
    if(enlarge){
        ofSetColor(255, 0, 0);
    }else{
        ofSetColor(0, 0, 255);
    }
    ofRect(x, y, width, width);
}


bool testApp::rolloverIdentifier(int mx, int my, int _x){
    x =_x;
    if(mx > x-width/2-6 && mx < x+width/2+6 && my > y-width/2-6 && my < y+width/2+6){
        return true;
    }
    return false;
}


void testApp::rollover(int mx, int my, float _x){
    x =_x;
    if(mx > x-width/2-6 && mx < x+width/2+6 && my > y-width/2-6 && my < y+width/2+6){
        enlarge = true;
    }else{
        enlarge = false;
    }
}

void testApp::displayLetter(int mx, int my, float _x, ofColor _color){
    x=_x;
    if(enlarge){
        ofSetColor(_color);
        ofRect(x, y-padding, width+(padding*2), width+(padding*2));
    }else{
        ofSetColor(_color);
        ofRect(x, y, width, width);
    }
}


void testApp::displayFont(string _buttons, int _x, ofColor _color){
    x=_x;
    if(enlarge){
        ofSetColor(_color);
        fontKeys.drawString(_buttons, x, y);
    }else{
        ofSetColor(_color);
        fontKeys.drawString(_buttons, x, y);
    }
}