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
  int mouseX;
  int mouseY;

  SDL_GetMouseState(&mouseX, &mouseY);
  SDL_PollEvent(&event);
  switch (event.type) {
    case SDL_QUIT:
      this->isRunning = false;
      break;
    case SDL_KEYDOWN:
      keyDownKeyboard(event);
    case SDL_MOUSEBUTTONDOWN:
      mouseButtonDown();
    default:
      break;
  }
}

void State::keyDownKeyboard(SDL_Event event) {
  switch (event.key.keysym.sym) {
    case SDLK_ESCAPE:
      this->isRunning = false;
      break;
    default:
      break;
  }
}

void State::mouseButtonDown() {}
