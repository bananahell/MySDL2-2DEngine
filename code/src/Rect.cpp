#include "Rect.h"

Rect::Rect() {
  posX = 0;
  posY = 0;
  width = 0;
  height = 0;
}

Rect::Rect(float posX, float posY, float width, float height) {
  this->posX = posX;
  this->posY = posY;
  this->width = width;
  this->height = height;
}

Rect::~Rect() {}

void Rect::setPos(float posX, float posY) {
  this->posX = posX;
  this->posY = posY;
}

void Rect::setPos(Vec2 pos) {
  this->posX = pos.posX;
  this->posY = pos.posY;
}

void Rect::setSize(float width, float height) {
  this->width = width;
  this->height = height;
}

void Rect::setSize(Vec2 size) {
  this->width = size.posX;
  this->height = size.posY;
}

void Rect::setCenter(float posX, float posY) {
  this->posX = posX - (width / 2);
  this->posY = posY - (height / 2);
}

void Rect::setCenter(Vec2 pos) {
  posX = pos.posX - (width / 2);
  posY = pos.posY - (height / 2);
}

bool Rect::contains(float xCoord, float yCoord) {
  if (xCoord >= this->posX && yCoord >= this->posY &&
      xCoord <= this->posX + this->width &&
      yCoord <= this->posY + this->height) {
    return true;
  }
  return false;
}

bool Rect::contains(Vec2 position) {
  return ((position.posX > posX) && (position.posX < posX + width) &&
          (position.posY > posY) && (position.posY < posY + height));
}

Vec2 Rect::getPos() {
  return Vec2(posX, posY);
}

Vec2 Rect::getSize() {
  return Vec2(width, height);
}

Vec2 Rect::getCenter() {
  return Vec2(posX + (width / 2), posY + (height / 2));
}
