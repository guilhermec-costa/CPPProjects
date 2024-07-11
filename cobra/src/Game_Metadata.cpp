#include "Game_Metadata.h"

Game_Metadata::Game_Metadata()
	: state(new Game_State())
{
}

Game_State& Game_Metadata::get_game_state() const
{
	return *state;
}

void Game_Metadata::set_game_state(const Game_State& state)
{
	*(this->state) = state;
}