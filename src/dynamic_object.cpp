#include "dynamic_object.h"

#include <iostream>

DynamicObject::DynamicObject(std::string txr_path) : Entity(txr_path) {
  setWeightX(WEAK);
  setWeightY(WEAK);
}

void DynamicObject::update() { setVel(getVel().x, getVel().y + 0.28); }

void DynamicObject::setWeightDefaultX() { setWeightX(WEAK); }
void DynamicObject::setWeightDefaultY() { setWeightY(WEAK); }

