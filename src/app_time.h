//
//  app_time.h
//  physical-trial4
//
//  Created by OSAWASatoru on 6/17/17.
//
//

#pragma once
#include "ofMain.h"

class AppTime {
 public:
  AppTime() = default;
  void setup();
  void update();
  uint64_t getDeltaTimeMS() const {
    return elapsed_time_ - last_elapsed_time_;
  }
  float getDeltaTimeS() const {
    return static_cast<float>(elapsed_time_ - last_elapsed_time_) * 0.001;
  }

 private:
  uint64_t elapsed_time_;
  uint64_t last_elapsed_time_;
};
