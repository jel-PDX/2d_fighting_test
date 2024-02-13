#include "passive_object.h"

#include <iostream>

PassiveObject::PassiveObject(std::string txr_path) : Entity(txr_path) {
  setWeightX(NA);
  setWeightY(NA);
}

void PassiveObject::update() {}

void PassiveObject::setWeightDefaultX() { setWeightX(NA); }

void PassiveObject::setWeightDefaultY() { setWeightY(NA); }
