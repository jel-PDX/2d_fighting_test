#include "entity.h"

Entity::Entity(std::string txr_path) {
  e_txr.loadFromFile(txr_path);
  sf::Sprite spr{e_txr};
  e_spr = spr;
}

sf::Rect<float> Entity::getBounds() { return e_spr.getGlobalBounds(); }

sf::Vector2<float> Entity::getPos() { return e_pos; }

void Entity::setPos(float x, float y) {
  e_pos.x = x;
  e_pos.y = y;
  e_spr.setPosition(e_pos.x, e_pos.y);
}

void Entity::setPos(sf::Vector2<float> pos) {
  e_pos = pos;
  e_spr.setPosition(e_pos);
}

sf::Vector2<float> Entity::getVel() { return e_vel; }

void Entity::setVel(float x, float y) {
  e_vel.x = x;
  e_vel.y = y;
}

void Entity::setVel(sf::Vector2<float> vel) { e_vel = vel; }

sf::Sprite Entity::getSpr() { return e_spr; }

void Entity::setSpr(std::string txr_path) {
  e_txr.loadFromFile(txr_path);
  sf::Sprite spr{e_txr};
  spr.setScale(4, 4);
  e_spr = spr;
}

Entity::Weight Entity::getWeightX() { return e_weight_x; }

Entity::Weight Entity::getWeightY() { return e_weight_y; }

void Entity::setWeightX(Weight weight_x) { e_weight_x = weight_x; }

void Entity::setWeightY(Weight weight_y) { e_weight_y = weight_y; }

std::size_t Entity::getHash() { return std::hash<const Entity*>{}(this); }
