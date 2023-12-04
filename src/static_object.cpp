#include "static_object.h"

#include <iostream>

StaticObject::StaticObject(std::string txr_path) : Entity(txr_path) {
  setWeightX(STRONG);
  setWeightY(STRONG);
}

void StaticObject::update() {}

void StaticObject::setWeightDefaultX() {}

void StaticObject::setWeightDefaultY() {}
