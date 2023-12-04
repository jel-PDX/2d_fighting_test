#include "player.h"

#include <iostream>

Player::Player(std::string txr_path)
    : Entity(txr_path), p_dir{HALT}, p_jump_state{NO_JUMP} {
  setWeightX(MIDDLE);
  setWeightY(MIDDLE);
}

void Player::update() {
  if (p_dir == HALT)
    setVel(0, getVel().y);
  else if (p_dir == LEFT)
    setVel(-2.5, getVel().y);
  else if (p_dir == RIGHT)
    setVel(2.5, getVel().y);

  if (getVel().y > 0 || getVel().y < 0)
    p_jump_state = FREE_FALL;
  else if (p_jump_state == JUMP)
    setVel(getVel().x, -6.25);
  else
    p_jump_state = NO_JUMP;

  setVel(getVel().x, getVel().y + 0.28);
}

void Player::setMoveDir(MoveDir dir) { p_dir = dir; }

void Player::setJump(JumpState jump_state) { p_jump_state = jump_state; }

Player::JumpState Player::getJump() { return p_jump_state; }

void Player::setWeightDefaultX() { setWeightX(MIDDLE); }

void Player::setWeightDefaultY() { setWeightY(MIDDLE); }
