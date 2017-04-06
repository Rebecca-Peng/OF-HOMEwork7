#pragma once

#include "ofMain.h"

class Line{
public:
    Line();
    void setup();
    void update();
    void draw();
    void move();
    
    ofPoint P[2];
    ofPoint t;
    
    int r2,g2,b2;
    
    float rX,rY,rZ;
    
    float fallSpeed;
    float fallWiggle;
    
};

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
		
        Line myCircle;
};
