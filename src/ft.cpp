#include "ft.h"

#include "entity.h"
#include "game_util.h"
#include "scene.h"

FT::FT() : ft_window_width{1280}, ft_window_height{720}, ft_scene_map{} {
  ft_window.create(sf::VideoMode{1280, 720}, "2d_fighting_test");
  ft_window.setPosition({400, 100});
  ft_window.setFramerateLimit(60);
}

sf::RenderWindow* FT::getWindow() { return &ft_window; }

void FT::addScene(string id) { ft_scene_map[id] = new Scene(); }

Scene* FT::getScene(string id) { return ft_scene_map[id]; }

void FT::renderScene(string id) {
  ft_window.clear();
  for (Entity* e : game_entities) ft_window.draw(e->getSpr());
  ft_window.display();
}
