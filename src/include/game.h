#include <SFML/Graphics.hpp>
#include <string>

class Player;

using std::string;

class Game {
 public:
  Player* g_player;

  Game();
  void addEntity(string txr_path, sf::Vector2<int> pos, char type);
};
