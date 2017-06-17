#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  //  ofSetFrameRate(60);
  ofSetVerticalSync(false);
  ofSetFrameRate(0);
  ofBackground(63);
  
  position_ = ofVec2f(100.0, ofGetHeight() * 0.5);
  velocity_ = ofVec2f(0.0, 0.0) * PX_PER_METER;

  app_time_.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
  velocity_ += acceleration_ * app_time_.getDeltaTimeS();
  position_ += velocity_ * app_time_.getDeltaTimeS();
  app_time_.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofDrawGrid(100, 11, false, false, false, true);
  ofDrawCircle(position_, 10);
  std::cout<<floor(0.1)<<std::endl;

  ofDrawBitmapString("frameRate = " + ofToString(ofGetFrameRate()), 10, 20);
  ofDrawBitmapString("acceleration = " + ofToString(acceleration_), 10, 40);
  ofDrawBitmapString("speed = " + ofToString(velocity_), 10, 60);
  ofDrawBitmapString("position = " + ofToString(position_), 10, 80);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch(key) {
    case OF_KEY_LEFT:
      acceleration_ += ofVec2f(-1.0, 0.0) * PX_PER_METER;
      break;
    case OF_KEY_RIGHT:
      acceleration_ += ofVec2f(1.0, 0.0) * PX_PER_METER;
      break;
    case OF_KEY_UP:
      acceleration_ += ofVec2f(0.0, -1.0) * PX_PER_METER;
      break;
    case OF_KEY_DOWN:
      acceleration_ += ofVec2f(0.0, 1.0) * PX_PER_METER;
      break;
    default:
      break;
  }
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
