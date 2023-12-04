#pragma once

#include "entity.h"

class DynamicObject : public Entity {
 private:
 public:
  DynamicObject(std::string txr_path);
  void update() override;
  void setWeightDefaultX() override;
  void setWeightDefaultY() override;
};
