#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

enum win_states {
  COULDNT_CREATE_WINDOW,
  CREATED
};

class Window {
public:
  static const int WIN_WIDTH = 800;
  static const int WIN_HEIGHT = 600;

public:
  static win_states check_win_integrity(SDL_Window *win);
};


#endif
