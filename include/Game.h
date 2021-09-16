#ifndef Game_h
#define Game_h

#include <iostream>

#include "SDL2/SDL.h"

class Game {
 public:
  Game();
  ~Game();
  void init(const char *, int, int, int, int, bool);
  void handleEvents();
  void update();
  void render();
  void clean();
  bool running() { return isRunning; }

 private:
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
};

#endif  // Game_h
