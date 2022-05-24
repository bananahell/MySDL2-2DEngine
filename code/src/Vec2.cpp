#include "Vec2.h"

#include <cmath>

Vec2::Vec2() {
  Vec2::posX = 0;
  Vec2::posY = 0;
}

Vec2::Vec2(float posX, float posY) {
  Vec2::posX = posX;
  Vec2::posY = posY;
}

Vec2::~Vec2() {}

Vec2 Vec2::operator+(const Vec2& opInput) const {
  return Vec2(this->posX + opInput.posX, this->posY + opInput.posY);
}

Vec2 Vec2::operator+(const float opInput) const {
  return Vec2(this->posX + opInput, this->posY + opInput);
}

Vec2 Vec2::operator-(const Vec2& opInput) const {
  return Vec2(this->posX - opInput.posX, this->posY - opInput.posY);
}

Vec2 Vec2::operator-(const float opInput) const {
  return Vec2(this->posX - opInput, this->posY - opInput);
}

Vec2 Vec2::operator*(const Vec2& opInput) const {
  return Vec2(this->posX * opInput.posX, this->posY * opInput.posY);
}

Vec2 Vec2::operator*(const float opInput) const {
  return Vec2(this->posX * opInput, this->posY * opInput);
}

Vec2 Vec2::operator/(const Vec2& opInput) const {
  return Vec2(this->posX / opInput.posX, this->posY / opInput.posY);
}

Vec2 Vec2::operator/(const float opInput) const {
  return Vec2(this->posX / opInput, this->posY / opInput);
}

Vec2 Vec2::rotate(float angle) {
  return Vec2(this->posX * cos(angle) - this->posY * sin(angle),
              this->posY * cos(angle) + this->posX * sin(angle));
}

float Vec2::getDiffX(float posX) {
  return posX - this->posX;
}

float Vec2::getDiffY(float posY) {
  return posY - this->posY;
}

float Vec2::getDiff(Vec2 pos) {
  return pow(pow(getDiffX(pos.posX), 2) + pow(getDiffY(pos.posY), 2), 0.5);
}

float Vec2::getCos(Vec2 pos) {
  return getDiffX(pos.posX) / getDiff(pos);
}

float Vec2::getSin(Vec2 pos) {
  return getDiffY(pos.posY) / getDiff(pos);
}

float Vec2::getAngle(Vec2 pos) {
  return atan2(getDiffY(pos.posY), getDiffX(pos.posX)) * (180 / M_PI);
}

float Vec2::cos(float angle) {
  return cos(angle * M_PI / 180);
}

float Vec2::sin(float angle) {
  return sin(angle * M_PI / 180);
}

Vec2 Vec2::project(float dist, float angle) {
  return Vec2(cos(angle) * dist, sin(angle) * dist);
}
