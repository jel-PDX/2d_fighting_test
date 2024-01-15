#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "collision.h"
#include "collisions_util.h"
#include "dynamic_object.h"
#include "entity.h"
#include "game.h"
#include "game_util.h"
#include "handle_global_collisions.h"
#include "player.h"
#include "spatial_hash_grid.h"
#include "static_object.h"

int main() {
  // Setup
  window.setPosition({400, 100});
  window.setFramerateLimit(60);

  Game game{};

  game.addEntity("../assets/player.png", {20, 300}, 'p');
  game.addEntity("../assets/small_box.png", {500, 300}, 'd');
  game.addEntity("../assets/small_box.png", {500, 200}, 'd');
  game.addEntity("../assets/big_box.png", {750, 572}, 's');
  game.addEntity("../assets/big_box.png", {750, 265}, 's');
  game.addEntity("../assets/small_box.png", {300, 300}, 'd');
  game.addEntity("../assets/ground.png", {0, 700}, 's');

  bool W_PRESSED{}, A_PRESSED{}, S_PRESSED{}, D_PRESSED{}, SPACE_PRESSED{};

  // Application Loop
  while (window.isOpen()) {
    sf::Event event;

    // Event Loop
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();

      if (event.key.code == sf::Keyboard::W) {
        if (event.type == sf::Event::KeyPressed) {
          W_PRESSED = true;
        } else if (event.type == sf::Event::KeyReleased) {
          W_PRESSED = false;
        }
      }

      if (event.key.code == sf::Keyboard::A) {
        if (event.type == sf::Event::KeyPressed) {
          A_PRESSED = true;
        } else if (event.type == sf::Event::KeyReleased) {
          A_PRESSED = false;
        }
      }

      if (event.key.code == sf::Keyboard::S) {
        if (event.type == sf::Event::KeyPressed) {
          S_PRESSED = true;
        } else if (event.type == sf::Event::KeyReleased) {
          S_PRESSED = false;
        }
      }

      if (event.key.code == sf::Keyboard::D) {
        if (event.type == sf::Event::KeyPressed) {
          D_PRESSED = true;
        } else if (event.type == sf::Event::KeyReleased) {
          D_PRESSED = false;
        }
      }

      if (event.key.code == sf::Keyboard::Space) {
        if (event.type == sf::Event::KeyPressed) {
          SPACE_PRESSED = true;
        } else if (event.type == sf::Event::KeyReleased) {
          SPACE_PRESSED = false;
        }
      }
    }

    // State Handling
    if (A_PRESSED) {
      game.g_player->setMoveDir(Player::LEFT);
    } else if (D_PRESSED) {
      game.g_player->setMoveDir(Player::RIGHT);
    } else
      game.g_player->setMoveDir(Player::HALT);

    if (SPACE_PRESSED && game.g_player->getJump() == Player::NO_JUMP)
      game.g_player->setJump(Player::JUMP);

    // Update Entities
    for (Entity* e : game_entities) e->update();

    // Handle Collisions
    handleGlobalCollisions();

    // Global Entities Movement
    for (Entity* e : game_entities)
      e->setPos(e->getPos().x + e->getVel().x, e->getPos().y + e->getVel().y);

    // Undo Nudge Velocities, Manage Gravity Accel
    for (Entity* e : game_entities) {
      sf::Vector2<float> nudge{world_nudges[e->getHash()]};
      if (nudge.y > 0) {
        e->setVel(e->getVel().x + nudge.x, 0);
      } else
        e->setVel(e->getVel().x + nudge.x, e->getVel().y + nudge.y);
    }
    world_nudges.clear();

    for (Entity* e : game_entities) SHG.updateEntity(e);

    // Rendering
    window.clear();
    for (Entity* e : game_entities) window.draw(e->getSpr());
    window.display();
  }
}
