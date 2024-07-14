#pragma once
#include "game.h"
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include "cobra_events.h"
#include "game_entity.h"
#include "vector"
#include "components/texture_component.h"

#define COBRA_SUBSYSTEMS (SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)

class Sdl_API : public IGame {
public:
	Sdl_API();
	~Sdl_API();
	void render() override;
	void update() override;
	void terminate() override;
	void handle_events() override;
	void setup_window(const char* title, int x, int y, int w, int h);
	void setup_renderer(SDL_RendererFlags);
	void init_subsystems();
	bool check_integrity() const;
	void add_entities(const std::vector<const Game_Entity*>&);
	SDL_Renderer* get_renderer() const;
	SDL_Window* get_window() const;
	Texture_Component* texture_component;
private:
	void init_event_handlers();
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Event* m_event_src;
	std::vector<const Game_Entity*> m_entities;
	Cobra_EVENTS m_events;
};
