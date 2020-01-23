
/*-----------------------------------------------------------------------------*/
/** @file   demobot.h
 * @brief   This is an optional file that you can use to write custom methods
 *          for a bot (such as types of turns, sensing, etc). You must extend
 *          one of the existing drive classes (currently fwd or chaindrive) or
 *          write your own, and declare your bot as the new type in your
 *          main file.
 *//*---------------------------------------------------------------------------*/

#include "vex.h"
#include "vext/vext.h"

#ifndef DEMOBOT_H
#define DEMOBOT_H

using namespace vex;

class demobot : public vext::fwd {
public:

  /*
   * Construct a chaindrive with left and right motors
   * @param left Left port
   * @param right Right port
   */
  demobot(vex::motor &leftA ,vex::motor &leftB, vex::motor &rightA, vex::motor &rightB) : vext::fwd(leftA, leftB, rightA, rightB) {
    //custom constructor actions 
  };
  
  void doCustomAction();
};

#endif

