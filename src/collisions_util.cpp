#include "collisions_util.h"

#include <SFML/Graphics.hpp>

#include "collision.h"
#include "entity.h"
#include "spatial_hash_grid.h"

bool isXCollision(Entity* e1, Entity* e2) {
  sf::Rect<float> e1_bbox{e1->getBounds()};
  sf::Rect<float> e2_bbox{e2->getBounds()};

  e1_bbox.left += e1->getVel().x;
  e2_bbox.left += e2->getVel().x;

  if (e1_bbox.intersects(e2_bbox)) return true;

  return false;
}

bool isYCollision(Entity* e1, Entity* e2) {
  sf::Rect<float> e1_bbox{e1->getBounds()};
  sf::Rect<float> e2_bbox{e2->getBounds()};

  e1_bbox.top += e1->getVel().y;
  e2_bbox.top += e2->getVel().y;

  if (e1_bbox.intersects(e2_bbox)) return true;

  return false;
}

Collision::ColDir* checkCollisionDir(Entity* e1, Entity* e2) {
  Collision::ColDir* col_dir{};

  if (isXCollision(e1, e2)) {
    col_dir = new Collision::ColDir{Collision::X_COL};
  } else if (isYCollision(e1, e2)) {
    col_dir = new Collision::ColDir{Collision::Y_COL};
  }

  return col_dir;
}

void generateCollision(
    Entity* e1, Entity* e2, Collision::ColDir col_dir,
    unordered_map<size_t, Collision>* world_collisions,
    unordered_map<size_t, sf::Vector2<float>>* world_nudges) {
  Collision new_collision(e1, e2, col_dir, world_nudges);
  world_collisions->insert({new_collision.getHash(), new_collision});
}
