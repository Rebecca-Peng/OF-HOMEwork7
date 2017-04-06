#pragma once

#include "ofMain.h"
#define Num 5

class Circle{
public:
    Circle();
    void setup(int w,int h);
    void updateColor(int r0,int g0,int b0,int r1,int g1, int b1);
    void updateRotate(float r1,float r2,float r3,float degree);
    void updateTranslate(float r1,float r2,int ram);
    void updateWiggle(float r1, int t1,int t2);
    void updateFall(float r1, int t1,int t2);
    void draw( );
    
    int r,g,b;
    int dim;
    
    ofPoint t;
    ofPoint P;
    
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
    
        Circle myCircles[Num];
		
};
