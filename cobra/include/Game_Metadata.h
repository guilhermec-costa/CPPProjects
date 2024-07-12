#pragma once

constexpr int HEALTH = 1;
constexpr int NOT_HEALTH = 0;

typedef enum {
	RUNNING,
	PAUSED,
	TERMINATED
} Game_State;

struct Game_Metadata {
private:
	Game_State m_state;
public:
	Game_Metadata();
	void set_game_state(const Game_State&);
	Game_State get_game_state() const;
};
