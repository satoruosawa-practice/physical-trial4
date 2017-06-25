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
  app_time_.update();
  sphere_.resetForce();

  if (push_duration_ > 0) {
    sphere_.addForce(push_force_);
    push_duration_ -= app_time_.getDeltaTimeMS();
  } else {
    push_force_ = ofVec2f(0.0, 0.0);
    push_duration_ = 0;
  }
  sphere_.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofDrawGrid(100, 11, false, false, false, true);
  sphere_.draw();

  ofDrawBitmapString("frameRate = " + ofToString(ofGetFrameRate()), 10, 20);
  sphere_.drawParameters();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  switch(key) {
    case OF_KEY_LEFT:
      push_force_ += ofVec2f(-1.0, 0.0);
      push_duration_ += 1000;
      break;
    case OF_KEY_RIGHT:
      push_force_ += ofVec2f(1.0, 0.0);
      push_duration_ += 1000;
      break;
    case OF_KEY_UP:
      push_force_ += ofVec2f(0.0, -1.0);
      push_duration_ += 1000;
      break;
    case OF_KEY_DOWN:
      push_force_ += ofVec2f(0.0, 1.0);
      push_duration_ += 1000;
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
