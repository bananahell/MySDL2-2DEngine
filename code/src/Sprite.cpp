#include "Sprite.h"

#include "Engine.h"

using namespace std;

Sprite::Sprite() {
  this->texture = nullptr;
  this->width = 0;
  this->height = 0;
}

Sprite::Sprite(string fileName) {
  this->texture = nullptr;
  this->open(fileName);
}

Sprite::~Sprite() {
  SDL_DestroyTexture(this->texture);
}

void Sprite::open(string fileName) {
  if (this->texture != nullptr) {
    SDL_DestroyTexture(this->texture);
  }
  this->texture =
      IMG_LoadTexture(Engine::engineInstance->renderer, fileName.c_str());
  if (this->texture == nullptr) {
    SDL_Log("Unable to initialize texture: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  if (SDL_QueryTexture(this->texture, nullptr, nullptr, &width, &height) != 0) {
    SDL_Log("Unable to initialize query texture: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  setClip(0, 0, this->width, this->height);
}

void Sprite::setClip(int posX, int posY, int width, int height) {
  this->clipRect.x = posX;
  this->clipRect.y = posY;
  this->clipRect.w = width;
  this->clipRect.h = height;
}

void Sprite::render(int posX, int posY) {
  SDL_Rect dstRect;
  dstRect.x = posX;
  dstRect.y = posY;
  dstRect.w = this->clipRect.w;
  dstRect.h = this->clipRect.h;
  if (SDL_RenderCopy(Engine::engineInstance->renderer, this->texture, &clipRect,
                     &dstRect) != 0) {
    SDL_Log("Unable to initialize render copy: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}
