#include "Game_Metadata.h"

Game_Metadata::Game_Metadata()
	: state()
{
	state = new Game_State();
	*state = Game_State::WHATEVER;
}

Game_State& Game_Metadata::get_game_state() const
{
	return *state;
}

void Game_Metadata::set_game_state(const Game_State& state)
{
	*(this->state) = state;
}