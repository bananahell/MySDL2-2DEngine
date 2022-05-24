#include "Music.h"

using namespace std;

Music::Music() {
  Music::music = nullptr;
}

Music::Music(string fileName) {
  Music::open(fileName);
}

void Music::play(int times) {
  Mix_PlayMusic(this->music, times);
}

void Music::stop(int msToStop) {
  Mix_FadeOutMusic(msToStop);
}

void Music::open(string fileName) {
  this->music = Mix_LoadMUS(fileName.c_str());
}
