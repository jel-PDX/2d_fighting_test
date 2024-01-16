#include "ft.h"

#include "entity.h"
#include "scene.h"

FT::FT() : ft_window_width{1280}, ft_window_height{720}, ft_scene_map{} {
  ft_window.create(sf::VideoMode{1280, 720}, "2d_fighting_test");
  ft_window.setPosition({400, 100});
  ft_window.setFramerateLimit(60);
}

sf::RenderWindow* FT::getWindow() { return &ft_window; }

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
