#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <vector>

#include "collision.h"
#include "spatial_hash_grid.h"

class Player;
class Entity;
class FT;

using std::size_t;
using std::string;
using std::unordered_map;
using std::vector;

class Scene {
 public:
  int s_num_cells_wide, s_num_cells_high;
  FT* s_ft;
  Player* s_player;
  vector<Entity*> s_game_entities;
  unordered_map<size_t, Collision> s_world_collisions;
  unordered_map<size_t, sf::Vector2<float>> s_world_nudges;
  SpatialHashGrid s_SHG;

  Scene();
  Scene(FT* ft);
  void addEntity(string txr_path, sf::Vector2<int> pos, char type);
  void update();
  void handleCollisions();
  void writeMovement();
  void undoNudges();
  void render();
};
