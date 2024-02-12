#include "ft.h"

#include "entity.h"
#include "player.h"
#include "scene.h"

FT::FT() : ft_window_width{1280}, ft_window_height{720}, ft_scene_map{} {}

void FT::addScene(string id) { ft_scene_map[id] = new Scene(this); }

void FT::selectScene(string id) { select_id = id; }

void FT::addEntity(string txr_path, sf::Vector2<int> pos, char type) {
  ft_scene_map[select_id]->addEntity(txr_path, pos, type);
}

void FT::updateScene() { ft_scene_map[select_id]->update(); }

void FT::handleColScene() { ft_scene_map[select_id]->handleCollisions(); }

void FT::writeScene() { ft_scene_map[select_id]->writeMovement(); }

void FT::renderScene() { ft_scene_map[select_id]->render(); }

void FT::undoNudgesScene() { ft_scene_map[select_id]->undoNudges(); }

Player* FT::getPlayer() { return ft_scene_map[select_id]->s_player; }

void FT::runScene() {
  // Create window if not already created
  if (!ft_window.isOpen()) createWindow();

  // Game Loop
  while (ft_window.isOpen()) {
    sf::Event event;

    // Event Loop
    while (ft_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) ft_window.close();

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
      getPlayer()->setMoveDir(Player::LEFT);
    } else if (D_PRESSED) {
      getPlayer()->setMoveDir(Player::RIGHT);
    } else
      getPlayer()->setMoveDir(Player::HALT);

    if (SPACE_PRESSED && getPlayer()->getJump() == Player::NO_JUMP)
      getPlayer()->setJump(Player::JUMP);

    // Update Entities
    updateScene();

    // Handle Collisions
    handleColScene();

    // Global Entities Movement
    writeScene();

    // Undo Nudge Velocities, Manage Gravity Accel
    undoNudgesScene();

    // Rendering
    renderScene();
  }
}

void FT::createWindow() {
  ft_window.create(sf::VideoMode{1280, 720}, "2d_fighting_test");
  ft_window.setPosition({400, 100});
  ft_window.setFramerateLimit(60);
}
