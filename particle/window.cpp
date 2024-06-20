#include "window.h"
#include <cstddef>

win_states Window::check_win_integrity(SDL_Window *win) {
  if(win == NULL) {
    return win_states::COULDNT_CREATE_WINDOW;
  }
  return win_states::CREATED;
}
