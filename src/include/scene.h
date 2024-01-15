#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Player;

using std::string;

class Scene {
 public:
  Player* s_player;

  Scene();
  void addEntity(string txr_path, sf::Vector2<int> pos, char type);
};
