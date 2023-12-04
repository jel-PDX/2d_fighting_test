#pragma once
#include <SFML/Graphics.hpp>

class Entity {
 public:
  enum Weight { WEAK, MIDDLE, STRONG };

 private:
  sf::Texture e_txr;
  sf::Sprite e_spr;
  sf::Vector2<float> e_pos;
  sf::Vector2<float> e_vel;
  Weight e_weight_x;
  Weight e_weight_y;

 public:
  Entity(std::string txr_path);
  virtual void update() = 0;
  sf::Rect<float> getBounds();

  sf::Vector2<float> getPos();
  void setPos(float x, float y);
  void setPos(sf::Vector2<float> pos);
  sf::Vector2<float> getVel();
  void setVel(float x, float y);
  void setVel(sf::Vector2<float> vel);
  sf::Sprite getSpr();
  void setSpr(std::string txr_path);
  Weight getWeightX();
  Weight getWeightY();
  void setWeightX(Weight collision_weight_x);
  void setWeightY(Weight collision_weight_y);
  std::size_t getHash();
  virtual void setWeightDefaultX() = 0;
  virtual void setWeightDefaultY() = 0;
};
