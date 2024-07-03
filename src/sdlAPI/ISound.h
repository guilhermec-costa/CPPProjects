#ifndef ISOUND_H
#define ISOUND_H
#include <SDL2/SDL_audio.h>
#include <iostream>

class ISound {
public:
    virtual void play_sound() = 0;
    virtual void stop_sound() = 0;
};

class SDL_Sound : public ISound {
public:
  SDL_Sound(std::string audio_path);
  ~SDL_Sound();
  void play_sound();
  void stop_sound();
  void setup_device();

private:
  SDL_AudioDeviceID m_device;
  SDL_AudioSpec m_audio_spec;
  Uint8* m_wave_start;
  Uint32 m_wave_length;
};

#endif
