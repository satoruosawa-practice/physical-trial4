//
//  sphere.h
//  physical-trial4
//
//  Created by OSAWASatoru on 6/17/17.
//
//

#pragma once

#include "ofMain.h"
#include "./global_definition.h"
#include "./app_time.h"

class Sphere {
 public:
  Sphere() = default;
  Sphere(AppTime * app_time);
  void setup();
  void update();
  // getter
  const ofVec2f getPosition() { return position_; }
  const ofVec2f getVelocity() { return velocity_; }
  const ofVec2f getAcceleration() { return acceleration_; }
  // setter
  void setPosition(const ofVec2f &p) { position_ = p; }
  void setVelocity(const ofVec2f &v) { velocity_ = v; }
  void setAcceleration(const ofVec2f &a) { acceleration_ = a; }
  // add
  void addPosition(const ofVec2f &p) { position_ += p; }
  void addVelocity(const ofVec2f &v) { velocity_ += v; }
  void addAcceleration(const ofVec2f &a) { acceleration_ += a; }

 private:
  ofVec2f position_;
  ofVec2f velocity_;  // m/s
  ofVec2f acceleration_;  // m/s2
  AppTime * app_time_;
};
