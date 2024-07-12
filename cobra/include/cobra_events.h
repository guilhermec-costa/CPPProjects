#pragma once
#include <iostream>

typedef void (*quit_event_handler)(void);
struct {
	quit_event_handler quit_event;
} Cobra_EVENTS;

void _quit_event();
