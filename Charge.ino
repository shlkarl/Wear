#include "Charge.h"

CHARGE::CHARGE() {analogReadResolution(12); charge = analogRead(0)/41; }

int CHARGE::getCharge() {
  charge = analogRead(0)/41; 
  charging = false;
  if(charging)
    return -charge;
  else
    return charge;
}
