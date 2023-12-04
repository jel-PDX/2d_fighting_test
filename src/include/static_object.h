#pragma once

#include "entity.h"

class StaticObject : public Entity {
 public:
  StaticObject(std::string txr_path);
  void update() override;
  void setWeightDefaultX() override;
  void setWeightDefaultY() override;
};
