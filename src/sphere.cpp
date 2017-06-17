//
//  sphere.cpp
//  physical-trial4
//
//  Created by OSAWASatoru on 6/17/17.
//
//

#include "./sphere.h"
Sphere::Sphere(const AppTime &app_time) {
  app_time_ = &app_time;
}

void Sphere::setup() {
  acceleration_ = ofVec2f(0.0, 0.0) * PX_PER_METER;
//  acceleration_ += ofVec2f(0.0, 9.8) * PX_PER_METER;  // gravity
  velocity_ = ofVec2f(0.0, 0.0) * PX_PER_METER;
  position_ = ofVec2f(100.0, 0.0);
}

void Sphere::update(){
  velocity_ += acceleration_ * app_time_->getDeltaTimeS();
  position_ += velocity_ * app_time_->getDeltaTimeS();
}
