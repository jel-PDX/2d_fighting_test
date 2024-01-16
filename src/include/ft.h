#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class Scene;

using std::string;
using std::unordered_map;

class FT {
 private:
  int ft_window_width, ft_window_height;
  unordered_map<string, Scene*> ft_scene_map;
  sf::RenderWindow ft_window;

 public:
  FT();
  sf::RenderWindow* getWindow();

  void addScene(string id);
  Scene* getScene(string id);
  void updateScene(string id);
  void handleColScene(string id);
  void writeScene(string id);
  void renderScene(string id);
  void undoNudgesScene(string id);

  friend class Scene;
};
