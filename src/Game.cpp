#include "Game.h"

Game::Game() {
  this->isRunning = false;
  this->window = nullptr;
  this->renderer = nullptr;
}

Game::~Game() {}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "SDL initialized!!" << std::endl;
    this->window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
    if (this->window) {
      std::cout << "Window created!!" << std::endl;
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, 0);
    if (this->renderer) {
      SDL_SetRenderDrawColor(this->renderer, 255, 255, 0, 255);
      std::cout << "Renderer created!!" << std::endl;
    }
    this->isRunning = true;
  } else {
    this->isRunning = false;
  }
}

void Game::handleEvents() {
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

void Game::update() {}

void Game::render() {
  SDL_RenderClear(this->renderer);
  SDL_RenderPresent(this->renderer);
}

void Game::clean() {
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
  SDL_Quit();
  std::cout << "Game cleaned!!" << std::endl;
}
