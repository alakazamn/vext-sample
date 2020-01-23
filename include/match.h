#include "v5_apitypes.h"
#include "vex.h"
#include <iostream>

#include "vex_global.h"
#include "vex_thread.h"
#include "vex_units.h"

#include "vext/vext.h"

using namespace vex;

#ifndef MATCH_H
#define MATCH_H

class match {
public:

  /* This method is called before auton starts
   * change the parameters to whatever you need */
   
  static void pre_auton(vex::controller Controller, vex::brain Brain);


  /* This method is called when auton starts
   * change the parameters to whatever you need */

  static void auton(vext::fwd bot, vext::two intake, vex::motor ramp,
                    vex::motor tower);

  //write other custom methods for your bot here
};

#endif
