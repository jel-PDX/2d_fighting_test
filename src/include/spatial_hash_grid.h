#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

struct Entity;

struct SpatialHashGrid {
 private:
  sf::Vector2<float> s_bounds;      // x y dimensions in px
  sf::Vector2<float> s_dimensions;  // x y dimensions in cells
  float s_cell_width;
  float s_cell_height;

  // a vector for each cell position
  std::unordered_map<std::string, std::vector<Entity*>> s_cells;

  // pass in cell position, get hashable key
  std::string key(sf::Vector2<int> pos);

  std::vector<std::string> getEntityKeys(Entity* e);

 public:
  // default constructor
  SpatialHashGrid();

  // configures s_bounds, s_dimensions, s_cell_width/height
  SpatialHashGrid(sf::Vector2<float> bounds, sf::Vector2<float> dimensions);

  // same as constructor
  void setDimensions(sf::Vector2<float> bounds, sf::Vector2<float> dimensions);

  // entity e placed in grid based on its position
  void insertEntity(Entity* e);

  // returns grid position of coordinates
  sf::Vector2<int> getCellIndex(sf::Vector2<float> pos);

  // given some cell index (x, y), return a list containing:
  // (x+1, y), (x, y+1), (x-1, y), (x, y-1), (x+1, y+1),
  // (x+1, y-1), (x-1, y+1), (x-1, y-1)
  std::vector<sf::Vector2<int>> getSurroundingCellIndices(
      sf::Vector2<int> cell_index);

  // returns vector of all entities near entity e
  std::vector<Entity*> findNear(Entity* e);

  // updates position of entity e on grid
  void updateEntity(Entity* e);

  // removes entity e from grid
  void removeEntity(Entity* e);
};
