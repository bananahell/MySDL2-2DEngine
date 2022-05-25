#include "Sprite.h"

#include "Engine.h"

using namespace std;

Sprite::Sprite(GameObject& parent) : Component(parent) {
  this->texture = nullptr;
  this->width = 0;
  this->height = 0;
}

Sprite::Sprite(GameObject& parent, string fileName) : Component(parent) {
  this->texture = nullptr;
  this->open(fileName);
  this->parent.box.width = this->width;
  this->parent.box.height = this->height;
}

Sprite::~Sprite() {
  if (this->texture != nullptr) {
    SDL_DestroyTexture(this->texture);
  }
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

void Sprite::render() {
  SDL_Rect dstRect;
  dstRect.x = this->parent.box.posX;
  dstRect.y = this->parent.box.posY;
  dstRect.w = this->clipRect.w;
  dstRect.h = this->clipRect.h;
  if (SDL_RenderCopy(Engine::engineInstance->renderer, this->texture, &clipRect,
                     &dstRect) != 0) {
    SDL_Log("Unable to initialize render copy: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}

void Sprite::update() {}

bool Sprite::isType(string type) {
  return type.compare(SPRITE_TYPE) == 0;
}
