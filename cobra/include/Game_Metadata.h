#pragma once

enum Game_State {
	RUNNING,
	WHATEVER
};

struct Game_Metadata {
public:
	Game_State* state;
	Game_Metadata();
	void set_game_state(const Game_State&);
	Game_State& get_game_state() const;

};
