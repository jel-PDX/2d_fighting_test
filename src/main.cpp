#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "collision.h"
#include "collisions_util.h"
#include "dynamic_object.h"
#include "entity.h"
#include "ft.h"
#include "player.h"
#include "scene.h"
#include "spatial_hash_grid.h"
#include "static_object.h"

int main() {
  FT game{};
  game.addScene("1");
  game.selectScene("1");

  game.addEntity("../assets/player.png", {20, 300}, 'p');
  game.addEntity("../assets/small_box.png", {500, 300}, 'd');
  game.addEntity("../assets/small_box.png", {500, 200}, 'd');
  game.addEntity("../assets/big_box.png", {750, 572}, 's');
  game.addEntity("../assets/big_box.png", {750, 265}, 's');
  game.addEntity("../assets/small_box.png", {300, 300}, 'd');
  game.addEntity("../assets/ground.png", {0, 700}, 's');

  game.runScene();

  return 0;
}
