#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  position_ = ofVec2f(100.0, ofGetHeight() * 0.5);
  velocity_ = ofVec2f(1, 0.0) * PX_PER_METER;
  
  last_elapsed_time_ = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofApp::update(){
  uint64_t elapsed_time_ = ofGetElapsedTimeMillis();
  position_ += velocity_ * (elapsed_time_ - last_elapsed_time_) * 0.001;
  last_elapsed_time_ = elapsed_time_;
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofDrawGrid(100, 11, false, false, false, true);
  ofDrawCircle(position_, 10);
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
