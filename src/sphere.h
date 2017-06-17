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
  explicit Sphere(const AppTime &app_time);
  void setup();
  void update();
  void draw();
  void drawParameters();
  void resetForce();

  void addForce(const ofVec2f &f) {force_ += f; }

 private:
  void updateForce_();
  void updatePos_();
  void bounceOfWalls_();
  const AppTime * app_time_;

  ofVec2f position_;
  ofVec2f velocity_;  // m/s
  ofVec2f acceleration_;  // m/s2
  ofVec2f force_;  // N
  float radius_;
  float mass_;  // kg
  float cor_;  // coefficient of restitution
};
