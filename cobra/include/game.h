#pragma once
#include "Game_Metadata.h"

class IGame {
protected:
	Game_Metadata* m_metadata;
	bool is_health;
	IGame() : m_metadata(new Game_Metadata()), is_health(true) {};
public:
	virtual void terminate() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void handle_events() = 0;
	Game_Metadata& get_metadata()
	{
		return *this->m_metadata;
	}
};

