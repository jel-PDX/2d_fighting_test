#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define NUM_CELLS_WIDE 16
#define NUM_CELLS_HIGH 9

class Collision;

class Entity;

class SpatialHashGrid;

extern sf::RenderWindow window;

extern std::vector<Entity*> game_entities;

extern std::unordered_map<std::size_t, Collision> world_collisions;

extern std::unordered_map<std::size_t, sf::Vector2<float>> world_nudges;

extern SpatialHashGrid SHG;
