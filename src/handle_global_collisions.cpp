#include "handle_global_collisions.h"

#include <iostream>

#include "collision.h"
#include "collisions_util.h"
#include "entity.h"
#include "game_util.h"
#include "spatial_hash_grid.h"

void handleGlobalCollisions() {
  do {
    world_collisions.clear();

    for (Entity* e : game_entities) {
      std::vector<Entity*> nearby_list{SHG.findNear(e)};

      for (Entity* nearby : nearby_list) {
        Collision::ColDir* col_dir{checkCollisionDir(e, nearby)};

        if (col_dir != nullptr) {
          generateCollision(e, nearby, *col_dir);
        }
      }
    }

    for (auto slot : world_collisions) slot.second.resolve();
  } while (!world_collisions.empty());

  for (Entity* e : game_entities) {
    e->setWeightDefaultX();
    e->setWeightDefaultY();
  }
}
