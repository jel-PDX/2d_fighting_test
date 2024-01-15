#include "game.h"

#include "dynamic_object.h"
#include "game_util.h"
#include "player.h"
#include "spatial_hash_grid.h"
#include "static_object.h"

Game::Game() = default;

void Game::addEntity(string txr_path, sf::Vector2<int> pos, char type) {
  Entity* e{};
  // create static obj
  if (type == 's') {
    e = new StaticObject(txr_path);
    e->setPos(pos.x, pos.y);
  }
  // create dynamic obj
  else if (type == 'd') {
    e = new DynamicObject(txr_path);
    e->setPos(pos.x, pos.y);
  }
  // create player
  else if (type == 'p') {
    e = new Player(txr_path);
    e->setPos(pos.x, pos.y);
    g_player = (Player*)e;
  } else
    return;

  game_entities.push_back(e);
  SHG.insertEntity(e);
}
