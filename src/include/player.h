#pragma once
#include "entity.h"

class Player : public Entity {
 public:
  enum MoveDir { HALT, LEFT, RIGHT };
  enum JumpState { NO_JUMP, FREE_FALL, JUMP };

 private:
  MoveDir p_dir;
  JumpState p_jump_state;

 public:
  Player(std::string txr_path);
  void update() override;
  void setMoveDir(MoveDir dir);
  void setJump(JumpState jump_state);
  JumpState getJump();
  void setWeightDefaultX() override;
  void setWeightDefaultY() override;
};
