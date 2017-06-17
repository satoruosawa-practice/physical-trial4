#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
//  ofSetVerticalSync(false);
//  ofSetFrameRate(0);
  ofBackground(63);

  sphere_ = Sphere(app_time_);
  sphere_.setup();
  app_time_.setup();
}

//--------------------------------------------------------------
void ofApp::update() {
  sphere_.update();
  app_time_.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofDrawGrid(100, 11, false, false, false, true);
  sphere_.draw();

  ofDrawBitmapString("frameRate = " + ofToString(ofGetFrameRate()), 10, 20);
  ofDrawBitmapString("acceleration = " + ofToString(sphere_.getAcceleration()), 10, 40);
  ofDrawBitmapString("speed = " + ofToString(sphere_.getVelocity()), 10, 60);
  ofDrawBitmapString("position = " + ofToString(sphere_.getPosition()), 10, 80);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  switch(key) {
    case OF_KEY_LEFT:
      sphere_.addAcceleration(ofVec2f(-1.0, 0.0) * PX_PER_METER);
      break;
    case OF_KEY_RIGHT:
      sphere_.addAcceleration(ofVec2f(1.0, 0.0) * PX_PER_METER);
      break;
    case OF_KEY_UP:
      sphere_.addAcceleration(ofVec2f(0.0, -1.0) * PX_PER_METER);
      break;
    case OF_KEY_DOWN:
      sphere_.addAcceleration(ofVec2f(0.0, 1.0) * PX_PER_METER);
      break;
    case 'c':
      sphere_.setup();
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
