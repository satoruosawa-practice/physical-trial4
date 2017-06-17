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
  acceleration_ += ofVec2f(0.0, 9.8) * PX_PER_METER;  // gravity
  velocity_ = ofVec2f(0.0, 0.0) * PX_PER_METER;
  position_ = ofVec2f(100.0, 0.0);
  radius_ = 10.0;
  cor_ = 0.9;
}

void Sphere::update(){
  velocity_ += acceleration_ * app_time_->getDeltaTimeS();
  position_ += velocity_ * app_time_->getDeltaTimeS();
  bounceOfWalls_();
}

void Sphere::draw() {
  ofDrawCircle(position_, radius_);
}

void Sphere::bounceOfWalls_() {
  float xmin = radius_;
  float xmax = ofGetWidth() - radius_;
  float ymin = radius_;
  float ymax = ofGetHeight() - radius_;

  if (position_.x < xmin) {
    velocity_.x *= -cor_;
    position_.x = xmin + (xmin - position_.x);
  } else if (position_.x > xmax) {
    velocity_.x *= -cor_;
    position_.x = xmax - (position_.x - xmax);
  }
  if (position_.y < ymin) {
    velocity_.y *= -cor_;
    position_.y = ymin + (ymin - position_.y);
  } else if (position_.y > ymax) {
    velocity_.y *= -cor_;
    position_.y = ymax - (position_.y - ymax);
  }
}

