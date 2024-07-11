#pragma once

enum Game_State {
	RUNNING,
	PAUSED,
	TERMINATED
};

struct Game_Metadata {
private:
	Game_State* state;
public:
	Game_Metadata();
	void set_game_state(const Game_State&);
	Game_State& get_game_state() const;
};
