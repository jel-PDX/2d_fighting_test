#include "ft.h"

#include "scene.h"

FT::FT() = default;

void FT::addScene(string id) { ft_scene_map[id] = new Scene(); }

Scene* FT::getScene(string id) { return ft_scene_map[id]; }
