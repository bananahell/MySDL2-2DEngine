#include "Engine.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_ttf.h>

Engine* Engine::engineInstance = nullptr;

Engine::Engine() {
  if (Engine::engineInstance != nullptr) {
    exit(EXIT_FAILURE);
  }
  Engine::engineInstance = this;
  this->window = nullptr;
  this->renderer = nullptr;
  this->state = nullptr;
}

Engine::~Engine() {
  this->clean();
}

void Engine::initEngine(const char* title, int xPos, int yPos, int width,
                        int height, bool fullscreen) {
  // Initializes main SDL functions
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  // Initializes image handling functions
  if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0) {
    SDL_Log("Unable to initialize IMG: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  // Initializes music and sound handling functions
  if (Mix_Init(MIX_INIT_FLAC | MIX_INIT_OGG | MIX_INIT_MID | MIX_INIT_MP3 |
               MIX_INIT_MOD | MIX_INIT_OPUS) == 0) {
    SDL_Log("Unable to initialize MIX: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  // Initializes OpenAudio handling functions
  if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,
                    MIX_DEFAULT_CHANNELS, 1024) != 0) {
    SDL_Log("Unable to initialize OpenAudio: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  Mix_AllocateChannels(32);

  // Window creation
  this->window = SDL_CreateWindow(title, xPos, yPos, width, height, fullscreen);
  if (this->window == nullptr) {
    SDL_Log("Window is null: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  // Renderer creation
  this->renderer =
      SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
  if (this->renderer == nullptr) {
    SDL_Log("Renderer is null: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}

void Engine::clean() {
  Mix_CloseAudio();
  Mix_Quit();
  IMG_Quit();
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
  SDL_Quit();
  printf("Engine cleaned!!\n");
}
