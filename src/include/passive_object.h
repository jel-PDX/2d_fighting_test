#pragma once

#include "entity.h"
class PassiveObject : public Entity {
 public:
  PassiveObject(std::string txr_path);
  void update() override;
  void setWeightDefaultX() override;
  void setWeightDefaultY() override;
};
