#include "spatial_hash_grid.h"

#include <cmath>
#include <iostream>

#include "entity.h"

SpatialHashGrid::SpatialHashGrid(sf::Vector2<float> bounds,
                                 sf::Vector2<float> dimensions)
    : s_bounds{bounds},
      s_dimensions{dimensions},
      s_cell_width{bounds.x / dimensions.x},
      s_cell_height{bounds.y / dimensions.y} {}

std::string SpatialHashGrid::key(sf::Vector2<int> pos) {
  return std::to_string(pos.x) + "." + std::to_string(pos.y);
}

std::vector<std::string> SpatialHashGrid::getEntityKeys(Entity *e) {
  std::vector<std::string> keys_list{};
  sf::Rect<float> bbox{e->getBounds()};
  float bbox_bottom{bbox.top + bbox.height};
  float bbox_right{bbox.left + bbox.width};

  for (float i{bbox.top};; i += s_cell_height) {
    if (i > bbox_bottom) i = bbox_bottom;

    for (float j{bbox.left};; j += s_cell_width) {
      if (j > bbox_right) j = bbox_right;

      std::string new_key{key(getCellIndex({j, i}))};
      if (std::find(keys_list.begin(), keys_list.end(), new_key) ==
          keys_list.end())
        keys_list.push_back(key(getCellIndex({j, i})));

      if (j == bbox_right) break;
    }

    if (i == bbox_bottom) break;
  }

  return keys_list;
}

void SpatialHashGrid::insertEntity(Entity *e) {
  std::vector<std::string> e_keys{getEntityKeys(e)};

  for (std::string key : e_keys) s_cells[key].push_back(e);
}

sf::Vector2<int> SpatialHashGrid::getCellIndex(sf::Vector2<float> pos) {
  int x{(int)std::floor(pos.x / s_cell_width)};
  int y{(int)std::floor(pos.y / s_cell_height)};

  return {x, y};
}

std::vector<sf::Vector2<int>> SpatialHashGrid::getSurroundingCellIndices(
    sf::Vector2<int> cell_index) {
  std::vector<sf::Vector2<int>> surrounding_indices{};

  surrounding_indices.push_back({cell_index.x + 1, cell_index.y});
  surrounding_indices.push_back({cell_index.x, cell_index.y + 1});
  surrounding_indices.push_back({cell_index.x - 1, cell_index.y});
  surrounding_indices.push_back({cell_index.x, cell_index.y - 1});
  surrounding_indices.push_back({cell_index.x + 1, cell_index.y + 1});
  surrounding_indices.push_back({cell_index.x + 1, cell_index.y - 1});
  surrounding_indices.push_back({cell_index.x - 1, cell_index.y + 1});
  surrounding_indices.push_back({cell_index.x - 1, cell_index.y - 1});

  return surrounding_indices;
}

std::vector<Entity *> SpatialHashGrid::findNear(Entity *e) {
  std::vector<Entity *> near_list{};
  std::vector<std::string> e_keys{getEntityKeys(e)};

  std::vector<sf::Vector2<int>> surrounding_indices{
      getSurroundingCellIndices(getCellIndex(e->getPos()))};

  for (sf::Vector2<int> index : surrounding_indices) {
    std::string surrounding_key{key(index)};
    e_keys.push_back(surrounding_key);
  }

  for (std::string key : e_keys) {
    std::vector<Entity *> cell_entities{s_cells[key]};

    for (Entity *entity : cell_entities)
      if (entity != e) near_list.push_back(entity);
  }

  return near_list;
}

void SpatialHashGrid::updateEntity(Entity *e) {
  removeEntity(e);
  insertEntity(e);
}

void SpatialHashGrid::removeEntity(Entity *e) {
  std::vector<std::string> e_keys{getEntityKeys(e)};

  for (std::string key : e_keys) {
    std::vector<Entity *> &cell_entities{s_cells[key]};

    for (auto it{cell_entities.begin()}; it < cell_entities.end(); ++it) {
      if (*it == e) {
        cell_entities.erase(it);
      }
    }
  }
}

