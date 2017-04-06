#include "ofApp.h"

vector<Circle> Circles;

Circle::Circle(){}

void Circle::setup(int w,int h){

    P = ofPoint(ofRandom(w),ofRandom(h));
    
    t = ofPoint(ofGetWidth()/3, ofGetHeight()/3, 0);
    fallSpeed = ofRandom(0.1,0.9);
    fallWiggle = ofRandom(2,5);
    
    r = 155;
    g = 4;
    b = 255;
    
    dim = 5;
}


void Circle::updateColor(int r0,int g0,int b0,int r1,int g1, int b1){
    
    r = ofRandom(r0,r1);
    g = ofRandom(g0,g1);
    b = ofRandom(b0,b1);
}

void Circle::updateRotate(float r1,float r2,float r3,float degree){
    float time = ofGetElapsedTimef();
    
    rX = ofSignedNoise(time * r1) * degree;
    rY = ofSignedNoise(time * r2) * degree;
    rZ = ofSignedNoise(time * r3) * degree;
}

void Circle::updateTranslate(float r1,float r2,int ram){
    float time = ofGetElapsedTimef();
    float x = ofSignedNoise(time * r1) * ofRandom(0,ram);
    float y = ofSignedNoise(time * r2) * ofRandom(0,ram);
    
    t = ofPoint(x,y);
//    if(x < 0 || x> ofGetWidth()) x = ofRandom(ofGetWidth()/3,2 * ofGetWidth()/3);
//    if(y <0 || y > ofGetHeight()) y = ofRandom(ofGetHeight()/3,2 * ofGetHeight()/3);
    
}

void Circle::updateWiggle(float r1, int t1, int t2){
    
    float time = ofGetElapsedTimef();
    fallWiggle = ofSignedNoise(time * r1)*ofRandom(t1,t2);
    P.x += fallWiggle;

}

void Circle::updateFall(float r1, int t1, int t2){
    
    float time = ofGetElapsedTimef();
    fallSpeed = ofSignedNoise(time * r1)*ofRandom(t1,t2);
    P.y += fallSpeed;
    
}

void Circle::draw(){
    ofPushMatrix();
        ofTranslate(t);
        ofRotateX(rX);
        ofRotateY(rY);
            ofPushStyle();
                ofSetColor(r,g,b);
                ofDrawCircle(P,dim);
            ofPopStyle();
    ofPopMatrix();
}

ofFbo fbo;
ofColor black(0,0,0);
//--------------------------------------------------------------
void ofApp::setup(){
    for(int i = 0; i < Num; i++){
        myCircles[i].setup(10 * i, 100 * i);
    }
//    myCircles[0].setup(10, 100);
//    myCircles[1].setup(10, 200);
//    myCircles[2].setup(10, 300);
//    myCircles[3].setup(10, 400);
//    myCircles[4].setup(10, 500);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    //fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    ofSetBackgroundColor(black);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myCircles[0].updateRotate(0.9, 0.3, 0.1, 360.0);
    for(int i = 1; i < Num; i++){
        myCircles[i].updateRotate(0.5, 0.2, 0.9, 180.0);
    }
    
    myCircles[0].updateTranslate(0.2, 0.2, 3);
    myCircles[1].updateTranslate(0.8, 0.1, 10);
    myCircles[2].updateTranslate(0.2, 0.2, 3);
    myCircles[3].updateTranslate(0.2, 0.2, 5);
    myCircles[4].updateTranslate(0.2, 0.7, 5);
    
    myCircles[0].updateWiggle(0.3, 2, 5);
    myCircles[1].updateWiggle(0.3, 2, 5);
    myCircles[2].updateWiggle(0.9, 1, 10);
    myCircles[3].updateWiggle(0.3, 2, 5);
    myCircles[4].updateWiggle(0.3, 2, 5);
    
    myCircles[0].updateFall(0.5, 0.1, 0.5);
    myCircles[1].updateFall(0.5, 0.1, 0.5);
    myCircles[2].updateFall(0.5, 0.1, 0.5);
    myCircles[3].updateFall(0.8, 0.1, 0.8);
    myCircles[4].updateFall(0.5, 0.1, 0.5);
    
    myCircles[0].updateColor(1, 3, 240, 255, 99,100);
    myCircles[1].updateColor(1, 3, 240, 255, 99, 110);
    myCircles[2].updateColor(1, 3, 240, 255, 99, 100);
    myCircles[3].updateColor(1, 3, 240, 255, 99, 110);
    myCircles[4].updateColor(237, 239, 23, 25, 100, 240);
    
    for(int i = 0; i <Num; i ++){
        if(myCircles[i].t.x<0 || myCircles[i].t.x > ofGetWidth()){
            myCircles[i].t.x = ofGetWidth()/2;
        }
        if(myCircles[i].t.y<0 || myCircles[i].t.y > ofGetHeight()){
            myCircles[i].t.y = ofGetHeight()/2;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
    ofPushStyle();
    ofSetColor(0,0,0,1);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPopStyle();
    
    for(int i = 0; i<Num; i ++){
        myCircles[i].draw();
    }
    fbo.end();
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
