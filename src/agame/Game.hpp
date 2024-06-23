#ifndef GAME_HPP
#define GAME_HPP

namespace sdlgame {
class Game {
private:
  bool is_runnning;
public: 
  Game();
  virtual ~Game();
  bool get_game_state() const;
};
} // namespace sdlgame
#endif
