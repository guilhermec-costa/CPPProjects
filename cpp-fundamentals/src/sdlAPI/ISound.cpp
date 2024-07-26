#include "ISound.h"
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_system.h>

SDL_Sound::SDL_Sound(std::string audio_path) {
	if (SDL_LoadWAV(audio_path.c_str(), &m_audio_spec, &m_wave_start, &m_wave_length) == nullptr) {
		std::cout << "Error loading sound" << std::endl;
	}
	else {
		std::cout << "WAV file loaded" << std::endl;
	}
}

SDL_Sound::~SDL_Sound() {
	SDL_FreeWAV(m_wave_start);
	SDL_CloseAudioDevice(m_device);
}

void SDL_Sound::play_sound() {
	int status = SDL_QueueAudio(m_device, m_wave_start, m_wave_length);
	SDL_PauseAudioDevice(m_device, 0);
	std::cout << m_device << std::endl;
}

void SDL_Sound::stop_sound() {
	SDL_PauseAudioDevice(m_device, 1);
}

void SDL_Sound::setup_device() {
	m_device = SDL_OpenAudioDevice(nullptr, 0, &m_audio_spec, nullptr, SDL_AUDIO_ALLOW_ANY_CHANGE);
	if (m_device == 0) {
		std::cout << "Failed to load sound device" << std::endl;
	}
}
