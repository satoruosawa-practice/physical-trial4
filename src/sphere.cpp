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
  radius_ = 10.0;
  mass_ = 1.0;
  setup();
}

void Sphere::setup() {
  acceleration_ = ofVec2f(0.0, 0.0);
  force_ = ofVec2f(0.0, 0.0);
  acceleration_ += ofVec2f(0.0, 0.0);
  velocity_ = ofVec2f(0.0, 0.0);
  position_ = ofVec2f(ofGetWidth() * 0.5, radius_);
}


void Sphere::update(){
  updateForce_();
  updatePos_();
}

void Sphere::resetForce() {
  force_ = ofVec2f(0.0, 0.0);
}

void Sphere::updateForce_() {
//  force_ += ofVec2f(0.0, GRAVITY) * mass_;
}

void Sphere::updatePos_() {
  acceleration_ = force_ / mass_ * PX_PER_METER;
  velocity_ += acceleration_ * app_time_->getDeltaTimeS();
  position_ += velocity_ * app_time_->getDeltaTimeS();
  bounceOfWalls_();
}

void Sphere::draw() {
  ofDrawCircle(position_, radius_);
}

void Sphere::drawParameters() {
  ofDrawBitmapString("coefficient of restitution = " + ofToString(cor_) +
                     " mass = " + ofToString(mass_) + " kg", 10, 60);
  ofDrawBitmapString("acceleration = " +
    ofToString(acceleration_ / static_cast<float>(PX_PER_METER)) +
    " m/s2", 10, 80);
  ofDrawBitmapString("speed = " +
    ofToString(velocity_ / static_cast<float>(PX_PER_METER)) +
    " m/s", 10, 100);
  ofDrawBitmapString("position = " +
                     ofToString(position_ / static_cast<float>(PX_PER_METER)) +
                     " m", 10, 120);
}

void Sphere::bounceOfWalls_() {
  cor_ = 0.9;
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


