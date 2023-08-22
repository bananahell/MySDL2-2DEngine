#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <memory>
#include <string>
#include <vector>

#include "Rect.h"

class Component;

class GameObject {
 public:
  Rect box;
  std::vector<std::unique_ptr<Component>> components;
  bool isAlive;

  GameObject();
  ~GameObject();
  void update();
  void render();
  void addComponent(Component*);
  void removeComponent(const Component*);
  Component* getComponent(const std::string&);
};

#endif  // GAMEOBJECT
