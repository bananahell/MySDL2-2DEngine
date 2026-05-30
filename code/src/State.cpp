#include "State.h"

#include <SDL2/SDL.h>

#include <algorithm>
#include <iostream>

#include "Engine.h"

using namespace std;

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
  for (unsigned i = 0; i < this->objectVector.size(); i++) {
    this->objectVector.at(i).get()->render();
  }
}

void State::addGameObject(GameObject* gameObject) {
  if (gameObject == nullptr) {
    cout << "[ERR] Tried to add null game object to state!" << endl;
    exit(EXIT_FAILURE);
  }
  if (gameObject->parent != nullptr) {
    cout << "[ERR] Tried adding to state a game object already with parent!"
         << endl;
    exit(EXIT_FAILURE);
  }
  if (this->findGameObject(gameObject)) {
    cout << "[ERR] Tried adding game object to state that already had it!"
         << endl;
    exit(EXIT_FAILURE);
  }
  this->objectVector.emplace_back(gameObject);
  gameObject->parent = this;
}

bool State::findGameObject(GameObject* gameObjectIn) {
  return any_of(this->objectVector.begin(), this->objectVector.end(),
                [gameObjectIn](const unique_ptr<GameObject>& gameObject) {
                  return gameObject.get() == gameObjectIn;
                });
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
