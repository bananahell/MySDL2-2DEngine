#include "Music.h"

using namespace std;

Music::Music() { this->music = nullptr; }

Music::Music(const string& fileName) { this->open(fileName); }

void Music::play(int times) { Mix_PlayMusic(this->music, times); }

void Music::stop(int msToStop) { Mix_FadeOutMusic(msToStop); }

void Music::open(const string& fileName) {
  this->music = Mix_LoadMUS(fileName.c_str());
}
