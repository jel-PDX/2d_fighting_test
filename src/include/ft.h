#pragma once

#include <string>
#include <unordered_map>

class Scene;

using std::string;
using std::unordered_map;

class FT {
 private:
  unordered_map<string, Scene*> ft_scene_map;

 public:
  FT();
  void addScene(string id);
  Scene* getScene(string id);
};
