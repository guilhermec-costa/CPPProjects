#pragma once

class IGame {
public:
	virtual void play() = 0;
	virtual void terminate() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void event_cb() = 0;
};
