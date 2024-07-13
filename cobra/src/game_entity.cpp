#include "game_entity.h"

Game_Entity::Game_Entity(SDL_Renderer* renderer)
	: m_texture_component(nullptr), m_renderer(renderer)
{
}

void Game_Entity::add_texture_component(const char* path, RGBA rgba)
{

	m_texture_component = new Texture_Component(m_renderer, path, rgba);
}

Texture_Component* Game_Entity::get_texture_component() const
{
	return m_texture_component;
}

Game_Entity::~Game_Entity()
{
	delete m_texture_component;
}