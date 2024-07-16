#pragma once
#include "game_entity.h"

class Snake_Entity : public Game_Entity
{
public:
	Snake_Entity(SDL_Window* window, SDL_Renderer* renderer)
		: Game_Entity(window, renderer) {};
	void render() const override;
};
