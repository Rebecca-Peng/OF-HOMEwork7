#include "ofApp.h"

vector<Line> Lines;


Line::Line(){
    
}

void Line::setup(){

    // Line
    int w = ofRandom(0,ofGetWidth()/10);
    int h = ofRandom(0,ofGetHeight()/5);
    P[0]= ofPoint(w,h);
    P[1]=ofPoint(-1 * w,h);
    P[2]=ofPoint(w,h+5);
    P[3]=ofPoint(-1*w,h+5);
    
    t = ofPoint(ofGetWidth()/3, ofGetHeight()/3, 0);
    fallSpeed = ofRandom(0.1,0.9);
    fallWiggle = ofRandom(2,5);
    
    r = ofRandom(20,255);
    g = 20;
    b = 255;
    
    r2 = 255;
    g2 = 245;
    b2 = 55;
    
    //Circle
    P0 = ofPoint(10,10);
    dim = 10;
    dim2 = 3;
    P1 = ofPoint(0,10);
    P2 = ofPoint(10,0);
    
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
    
    rX2 = ofSignedNoise(time * 0.5) * 360.0;
    rY2 = ofSignedNoise(time * 0.7) * 360.0;
    rZ2 = ofSignedNoise(time * 0.9) * 360.0;
    
    rX3 = ofSignedNoise(time * 0.5) * 180.0;
    rY3 = ofSignedNoise(time * 0.2) * 180.0;

    
    float x =ofSignedNoise(time * 0.2) * ofRandom(0,3);
    float y =ofSignedNoise(time * 0.2) * ofRandom(0,3);
    float z = ofMap(ofSignedNoise(time * 0.2), -1, 1, -800, 800);
    t = ofPoint(x, y, z);
    if(x < 0 || x> ofGetWidth()) { x = ofSignedNoise(time * 0.2) * ofRandom(0,4);
        r2 = 3;
        g2 = 55;
        b2 = ofRandom(100,255);
}
    if(y <0 || y > ofGetHeight()){ y = ofSignedNoise(time * 0.2) * ofRandom(0,3);
        r2 = 3;
        g2 = 255;
        b2 = ofRandom(100,255);
}
    
    
    float x2 = ofMap(ofSignedNoise(time * 0.2), -1, 1, 0, ofGetWidth());
    float y2 = ofMap(ofSignedNoise(time * 0.3), -1, 1, 0, ofGetHeight());
    float z2 = ofMap(ofSignedNoise(time * 0.2), -1, 1, -800, 800);
    t2 = ofPoint(x2, y2, z2);

    
    fallSpeed = ofSignedNoise(time * 0.5)*ofRandom(0.1,0.5);
    fallWiggle = ofSignedNoise(time * 0.3)*ofRandom(2,10);
    
    for(int i = 0; i<4; i++) {
        
        if(i%4 == 0) {
            P[i].x += fallWiggle;
            P[i].y += fallSpeed * ofRandom(0,3);
        }
        else if(i%4==1){
            P[i].x += fallWiggle;
            P[i].y += fallSpeed * ofRandom(-3,0);
        }
        else if(i%4==2){
            P[i].x += fallWiggle;
            P[i].y += fallSpeed * ofRandom(0,5);
        }
        else {
            P[i].x += fallWiggle;
            P[i].y += fallSpeed * ofRandom(-5,0);
        }
//        if(P[i].y >ofGetHeight() || P[i].y< 0) P[i].y = 0;
//        else if(P[i].x > ofGetWidth() || P[i].x < 0) P[i].x = 0;
    }
    
    P0.x += fallWiggle * ofRandom(-1,0);
    dim = ofMap(ofSignedNoise(time * 0.5), -1, 1, 0, 20);
    P1.x += fallWiggle * ofRandom(0,1);
    P2.x += fallWiggle * ofRandom(-1,1);
    
    dim2 ++;
    if(dim2 > 20) dim2 --;
    else if(dim2 < 1) dim2 ++;
    
}
void Line::move(){
//    ofTranslate(t);
    
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    

}

void Line::move2(){

    ofTranslate(t);
    
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
}

void Line::move3(){
    
    ofTranslate(t2);

    ofRotateX(rX3);
    ofRotateY(rY3);

}

void Line::move4(){
    
    ofTranslate(t2);
    
    ofRotateX(rX3);
    ofRotateY(rY3);
    
}

void Line::draw(){
    ofPushMatrix();
        move();
            ofPushStyle();
                ofSetColor(r2,g2,b2);
                ofDrawLine(P[2], P[3]);
            ofPopStyle();
    ofPopMatrix();
}

void Line::draw2(){
    ofPushMatrix();
    move2();
    ofPushStyle();
    ofSetColor(r2,g2,b2);
    ofDrawLine(P[0], P[1]);
    ofPopStyle();
    ofPopMatrix();
}

void Line::draw3(){
    ofPushMatrix();
    move3();
    ofPushStyle();
    ofSetColor(4,253,244);
    ofDrawCircle(P0,dim);
    ofPopStyle();
    ofPopMatrix();
}

void Line::draw4(){
    ofPushMatrix();
    move4();
    ofPushStyle();
    ofSetColor(128,219,249);
    ofDrawCircle(P1,dim);
    ofPopStyle();
    ofPopMatrix();
}

void Line::draw5(){
    ofPushMatrix();
    move4();
    ofPushStyle();
//    ofSetColor(5,215,208);
    ofSetColor(r,g,b);
    ofDrawCircle(P2,dim2);
    ofPopStyle();
    ofPopMatrix();
}



ofFbo fbo;
ofColor black(0,0,0);

void ofApp::add(ofPoint l1,ofPoint l2){
    
    Line newLine;
    newLine.P0 = l1;
    newLine.P1 = l2;
    Lines.push_back(newLine);

}
//--------------------------------------------------------------
void ofApp::setup(){
//    for(int i = 0; i < Lines.size(); i ++){
//        Lines[i].setup();
//    }
    myLine.setup();
    myLine2.setup();
    myCircle.setup();
    myCircle2.setup();
    myCircle3.setup();

    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    //fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    ofSetBackgroundColor(black);

}

//--------------------------------------------------------------
void ofApp::update(){
//    for(int i = 0; i < Lines.size(); i ++){
//        Lines[i].update();
//    }
    myLine.update();
    myLine2.update();
    myCircle.update();
    myCircle2.update();
    myCircle3.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofPushStyle();
        ofSetColor(0,0,0,1);
        ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPopStyle();
    
//    for(Line l : Lines){
//        l.draw();
//    }
    myLine.draw();
    myLine2.draw2();
    myCircle.draw3();
    myCircle2.draw4();
    myCircle3.draw5();
//    for(int i = 0; i<Lines.size();i ++){
//        Lines[i].draw();
//    }
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
    add(ofPoint(-20,0),ofPoint(20,0));
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
