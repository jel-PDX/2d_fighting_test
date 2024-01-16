#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "collision.h"
#include "collisions_util.h"
#include "dynamic_object.h"
#include "entity.h"
#include "ft.h"
#include "game_util.h"
#include "handle_global_collisions.h"
#include "player.h"
#include "scene.h"
#include "spatial_hash_grid.h"
#include "static_object.h"

int main() {
  // Setup
  FT game{};
  game.addScene("1");
  game.selectScene("1");

  game.addEntity("../assets/player.png", {20, 300}, 'p');
  game.addEntity("../assets/small_box.png", {500, 300}, 'd');
  game.addEntity("../assets/small_box.png", {500, 200}, 'd');
  game.addEntity("../assets/big_box.png", {750, 572}, 's');
  game.addEntity("../assets/big_box.png", {750, 265}, 's');
  game.addEntity("../assets/small_box.png", {300, 300}, 'd');
  game.addEntity("../assets/ground.png", {0, 700}, 's');

  bool W_PRESSED{}, A_PRESSED{}, S_PRESSED{}, D_PRESSED{}, SPACE_PRESSED{};

  // Application Loop
  while (game.getWindow()->isOpen()) {
    sf::Event event;

    // Event Loop
    while (game.getWindow()->pollEvent(event)) {
      if (event.type == sf::Event::Closed) game.getWindow()->close();

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
      game.getPlayer()->setMoveDir(Player::LEFT);
    } else if (D_PRESSED) {
      game.getPlayer()->setMoveDir(Player::RIGHT);
    } else
      game.getPlayer()->setMoveDir(Player::HALT);

    if (SPACE_PRESSED && game.getPlayer()->getJump() == Player::NO_JUMP)
      game.getPlayer()->setJump(Player::JUMP);

    // Update Entities
    game.updateScene();

    // Handle Collisions
    game.handleColScene();

    // Global Entities Movement
    game.writeScene();

    // Undo Nudge Velocities, Manage Gravity Accel
    game.undoNudgesScene();

    // Rendering
    game.renderScene();
  }
}
