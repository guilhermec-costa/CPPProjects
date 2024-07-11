#pragma once
#include "Game_Metadata.h"

class IGame {
protected:
	Game_Metadata* m_metadata;
	IGame() : m_metadata(new Game_Metadata()) {};
public:
	virtual void play() = 0;
	virtual void terminate() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void handle_events() = 0;
	Game_Metadata& get_metadata()
	{
		return *this->m_metadata;
	}
};

