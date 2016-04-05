#pragma once

#include "ofMain.h"
#include "ofxCsv.h"

using namespace wng;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    int curFile;
    int curImg;
    string curStr;
    
    int padTop;
    int padRight;
    int max;
    
    string picYear;
    string picTitle;
    
        ofImage img;
        ofxCsv csv;
    ofxCsv sorting;
    
    int imgHeight;
    
        string picID;
    
        //string path = "/Users/dsak/Projects/15 Outdoor Advertising Archive/isolated_faces_tosort";
    
        ofTrueTypeFont font;
    ofTrueTypeFont font2;
		
};
