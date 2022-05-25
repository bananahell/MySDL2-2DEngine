#ifndef COMPONENT
#define COMPONENT

#include <string>

#include "GameObject.h"

#define SPRITE_TYPE "Sprite"

class Component {
 public:
  GameObject& parent;

  explicit Component(GameObject&);

  virtual ~Component();

  virtual void update() = 0;
  virtual void render() = 0;
  virtual bool isType(std::string) = 0;
};

#endif  // COMPONENT
