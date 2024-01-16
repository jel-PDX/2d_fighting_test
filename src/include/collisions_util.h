#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "collision.h"

class Entity;

bool isXCollision(Entity* e1, Entity* e2);

bool isYCollision(Entity* e1, Entity* e2);

Collision::ColDir* checkCollisionDir(Entity* e1, Entity* e2);

void generateCollision(Entity* e1, Entity* e2, Collision::ColDir col_dir,
                       unordered_map<size_t, Collision>* world_collisions,
                       unordered_map<size_t, sf::Vector2<float>>* world_nudges);

