#include "Engine.h"

Engine::Engine() {
  this->isRunning = false;
  this->window = nullptr;
  this->renderer = nullptr;
}

Engine::~Engine() {}

void Engine::init(const char* title, int xPos, int yPos, int width, int height,
                  bool fullscreen) {
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    printf("SDL initialized!!\n");
    this->window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
    if (this->window) {
      printf("Window created!!\n");
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, 0);
    if (this->renderer) {
      SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
      printf("Renderer created!!\n");
    }
    this->isRunning = true;
  } else {
    this->isRunning = false;
  }
}

void Engine::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);
  printf("Entered handleEvents\n");
  switch (event.type) {
    case SDL_QUIT:
      this->isRunning = false;
      break;
    default:
      break;
  }
}

void Engine::render() {
  SDL_RenderClear(this->renderer);
  SDL_RenderPresent(this->renderer);
}

void Engine::clean() {
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
  SDL_Quit();
  printf("Engine cleaned!!\n");
}
