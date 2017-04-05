#include "ofApp.h"

Line::Line(){
    
}

void Line::setup(){
    
 P0 = ofPoint(10,10);
    
    r2 = 255;
    g2 = 245;
    b2 = 55;
    
}

void Line::update(){
    r2 = 3;
    g2 = 155;
    b2 = ofRandom(100,255);
    
    float time = ofGetElapsedTimef();
    
    rX = ofSignedNoise(time * 0.5) * 180.0;
    //    rY = ofSignedNoise(time * 0.5) * 180.0;
    rY= 0;
    //    rZ = ofSignedNoise(time * 0.2) * 180.0;
    rZ = 0;
    
    
    float x =ofSignedNoise(time * 0.2) * ofRandom(0,3);
    float y =ofSignedNoise(time * 0.2) * ofRandom(0,3);
    float z = ofMap(ofSignedNoise(time * 0.2), -1, 1, -800, 800);
    t = ofPoint(x, y, z);
    
    fallSpeed = ofSignedNoise(time * 0.5)*ofRandom(0.1,0.5);
    fallWiggle = ofSignedNoise(time * 0.3)*ofRandom(2,10);
    
    P0.x += fallWiggle * ofRandom(-1,0);
    
    dim = ofMap(ofSignedNoise(time * 0.5), -1, 1, 0, 20);


}

void Line::move(){
    ofTranslate(t);
    
    ofRotateX(rX);
    ofRotateY(rY);
    
    
}


void Line::draw(){
    ofPushMatrix();
    move();
    ofPushStyle();
    ofSetColor(r2,g2,b2);
    ofDrawCircle(P0,dim);
    ofPopStyle();
    ofPopMatrix();
}

ofFbo fbo;
ofColor black(0,0,0);


//--------------------------------------------------------------
void ofApp::setup(){
    myCircle.setup();
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    //fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    ofSetBackgroundColor(black);
}

//--------------------------------------------------------------
void ofApp::update(){
    myCircle.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofPushStyle();
    ofSetColor(0,0,0,1);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPopStyle();
    
    myCircle.draw();
    
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
