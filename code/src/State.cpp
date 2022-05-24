#include "State.h"

#include <SDL2/SDL.h>

#include "Engine.h"

State::~State() {}

void State::stateLoop() {
  while (this->isRunning == true) {
    this->handleEvents();
    this->update();
    this->render();
    SDL_RenderPresent(Engine::engineInstance->renderer);
    SDL_Delay(33);
  }
  delete this;
}

void State::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
    case SDL_QUIT:
      this->isRunning = false;
      break;
    default:
      break;
  }
}
