#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "entity.h"

using std::unordered_map;

class Collision {
 public:
  enum ColDir { X_COL, Y_COL };

 private:
  Entity* c_e1;
  Entity* c_e2;

  ColDir c_col_dir;

  unordered_map<size_t, sf::Vector2<float>>* c_world_nudges;

  sf::Vector2<float> nudge();

 public:
  Collision();
  Collision(Entity* e1, Entity* e2, ColDir col_dir,
            unordered_map<size_t, sf::Vector2<float>>* world_nudges);
  void resolve();
  void resolveImbalance(Entity::Weight w1, Entity::Weight w2);
  void resolveBalance(Entity::Weight w1, Entity::Weight w2);
  std::size_t getHash();
  struct HashFunction {
    std::size_t operator()(const Collision& collision) const {
      if (collision.c_e1 == nullptr || collision.c_e2 == nullptr) return 0;

      // Use the memory addresses of the entities to create a hash value
      std::size_t hash1 = std::hash<const Entity*>{}(collision.c_e1);
      std::size_t hash2 = std::hash<const Entity*>{}(collision.c_e2);

      // Combine the hashes in a way that doesn't depend on the order
      std::size_t combinedHash = hash1 ^ hash2;

      return combinedHash;
    }
  };
};
