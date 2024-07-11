#pragma once
#include "Game_Metadata.h"

class IGame {
private:
	Game_Metadata& m_metadata;
public:
	virtual void play() = 0;
	virtual void terminate() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void event_cb() = 0;
	Game_Metadata& get_metadata()
	{
		return this->m_metadata;
	}
};

