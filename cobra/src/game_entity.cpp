#include "game_entity.h"
#include <iostream>

Game_Entity::Game_Entity(SDL_Renderer* renderer)
	: m_texture_component(nullptr), m_collider_component(nullptr),
	m_renderer(renderer), m_visibility(Visibility::VISIBLE), m_status(NOT_ACTIVE)
{}

void Game_Entity::add_texture_component(const char* path, RGBA rgba)
{
	m_texture_component = new Texture_Component(m_renderer, path, rgba);
}

void Game_Entity::add_collider2D(Cobra_Rect* rect)
{
	m_collider_component = new Collider2D(rect);
}

void Game_Entity::render() const
{
	get_texture_component()->render();
	Collider2D* collider = get_collider_component();
	if (collider != nullptr)
	{
		collider->render(m_renderer);
	}
}

Texture_Component* Game_Entity::get_texture_component() const
{
	return m_texture_component;
}

Game_Entity::~Game_Entity()
{
	delete m_texture_component;
	delete m_collider_component;
}

void Game_Entity::set_visibility(Visibility visibility)
{
	m_visibility = visibility;
}

Visibility Game_Entity::is_visible() const
{
	return m_visibility;
}


Collider2D* Game_Entity::get_collider_component() const
{
	return m_collider_component;
}

Status Game_Entity::get_status() const 
{
	return m_status;
}