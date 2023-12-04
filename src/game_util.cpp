#include "game_util.h"

#include "collision.h"
#include "entity.h"
#include "spatial_hash_grid.h"

sf::RenderWindow window{sf::VideoMode{WINDOW_WIDTH, WINDOW_HEIGHT},
                        "2d_fighting_test"};

std::vector<Entity*> game_entities{};

std::unordered_map<std::size_t, Collision> world_collisions{};

std::unordered_map<std::size_t, sf::Vector2<float>> world_nudges{};

SpatialHashGrid SHG{{WINDOW_WIDTH, WINDOW_HEIGHT},
                    {NUM_CELLS_WIDE, NUM_CELLS_HIGH}};
