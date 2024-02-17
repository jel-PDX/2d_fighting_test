#include "scene.h"

#include "collision.h"
#include "collisions_util.h"
#include "dynamic_object.h"
#include "ft.h"
#include "passive_object.h"
#include "player.h"
#include "spatial_hash_grid.h"
#include "static_object.h"

Scene::Scene() : s_num_cells_wide{16}, s_num_cells_high{9} {
  s_SHG.setDimensions({s_ft->ft_window_width, s_ft->ft_window_height},
                      {s_num_cells_wide, s_num_cells_high});
}

Scene::Scene(FT* ft) : s_ft{ft}, s_num_cells_wide{16}, s_num_cells_high{9} {
  s_SHG.setDimensions({s_ft->ft_window_width, s_ft->ft_window_height},
                      {s_num_cells_wide, s_num_cells_high});
}

void Scene::addEntity(string txr_path, sf::Vector2<int> pos, char type) {
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
  // create passive obj
  else if (type == 'a') {
    e = new PassiveObject(txr_path);
    e->setPos(pos.x, pos.y);
    s_game_entities.push_back(e);
    return;
  }
  // create player
  else if (type == 'p') {
    e = new Player(txr_path);
    e->setPos(pos.x, pos.y);
    s_player = (Player*)e;
  } else
    return;

  s_game_entities.push_back(e);
  s_SHG.insertEntity(e);
}

void Scene::update() {
  for (Entity* e : s_game_entities) {
    e->update();
  }
}

void Scene::handleCollisions() {
  do {
    s_world_collisions.clear();

    for (Entity* e : s_game_entities) {
      if (e->getWeightX() == Entity::NA) {
        continue;  // discard passive objects
      }

      std::vector<Entity*> nearby_list{s_SHG.findNear(e)};

      for (Entity* nearby : nearby_list) {
        Collision::ColDir* col_dir{checkCollisionDir(e, nearby)};

        if (col_dir != nullptr) {
          generateCollision(e, nearby, *col_dir, &s_world_collisions,
                            &s_world_nudges);
        }
      }
    }

    for (auto slot : s_world_collisions) slot.second.resolve();
  } while (!s_world_collisions.empty());

  for (Entity* e : s_game_entities) {
    e->setWeightDefaultX();
    e->setWeightDefaultY();
  }
}

void Scene::writeMovement() {
  for (Entity* e : s_game_entities) {
    e->setPos(e->getPos().x + e->getVel().x, e->getPos().y + e->getVel().y);
    if (e->getWeightX() != Entity::NA) s_SHG.updateEntity(e);
  }
}

void Scene::undoNudges() {
  for (Entity* e : s_game_entities) {
    sf::Vector2<float> nudge{s_world_nudges[e->getHash()]};
    if (nudge.y > 0) {
      // limit gravity accel
      e->setVel(e->getVel().x + nudge.x, 0);
    } else
      e->setVel(e->getVel().x + nudge.x, e->getVel().y + nudge.y);
  }
  s_world_nudges.clear();
}

void Scene::render() {
  s_ft->ft_window.clear();
  for (Entity* e : s_game_entities) s_ft->ft_window.draw(e->getSpr());
  s_ft->ft_window.display();
}
