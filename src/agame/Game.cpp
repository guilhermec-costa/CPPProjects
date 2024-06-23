#include "Game.hpp"

namespace sdlgame {

Game::Game(): is_runnning(false) {}
bool Game::get_game_state() const {
  return is_runnning;
}
}
