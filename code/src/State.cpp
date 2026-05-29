#include "State.h"

#include <SDL2/SDL.h>

#include "Engine.h"

State::State() { this->quitRequested = false; }

State::~State() {}

void State::stateLoop() {
  while (this->quitRequested == false) {
    this->handleEvents();
    this->update();
    this->render();
    SDL_RenderPresent(Engine::engineInstance->renderer);
    SDL_Delay(Engine::engineInstance->framerate);
  }
  delete this;
}

void State::render() {
  for (unsigned i = 0; i < State::objectVector.size(); i++) {
    State::objectVector.at(i).get()->render();
  }
}

void State::handleEvents() {
  SDL_Event event;
  int mouseX;
  int mouseY;

  SDL_GetMouseState(&mouseX, &mouseY);
  SDL_PollEvent(&event);
  switch (event.type) {
    case SDL_QUIT:
      this->quitRequested = true;
      break;
    case SDL_KEYDOWN:
      keyDownKeyboard(event);
      break;
    case SDL_MOUSEBUTTONDOWN:
      mouseButtonDown();
      break;
    default:
      break;
  }
}

void State::keyDownKeyboard(SDL_Event event) {
  switch (event.key.keysym.sym) {
    case SDLK_ESCAPE:
      this->quitRequested = true;
      break;
    default:
      break;
  }
}

void State::mouseButtonDown() {}
