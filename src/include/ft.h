#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class Scene;
class Player;

using std::string;
using std::unordered_map;

class FT {
 private:
  bool W_PRESSED, A_PRESSED, S_PRESSED, D_PRESSED, SPACE_PRESSED, Q_PRESSED;
  int ft_window_width, ft_window_height;
  unordered_map<string, Scene*> ft_scene_map;
  sf::RenderWindow ft_window;
  bool ft_end;
  bool quit_active;
  string select_id;

  void createWindow();

  // Game loop util
  void updateScene();
  void handleColScene();
  void writeScene();
  void renderScene();
  void undoNudgesScene();

  Player* getPlayer();

 public:
  FT();

  void addScene(string id);
  void selectScene(string id);
  void addEntity(string txr_path, sf::Vector2<int> pos, char type);

  void runScene();

  friend class Scene;
};
