#pragma once

#include "ofMain.h"
#include "./app_time.h"
#define PX_PER_METER 10

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
		
  ofVec2f position_;
  ofVec2f velocity_;  // m/s
  ofVec2f acceleration_;  // m/s2
  
  AppTime app_time_;
};
