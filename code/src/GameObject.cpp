#include "GameObject.h"

#include "Component.h"

using namespace std;

GameObject::GameObject() : box(Rect()) {
  this->isAlive = true;
}

GameObject::~GameObject() {
  this->components.clear();
}

void GameObject::update() {
  for (int i = this->components.size() - 1; i >= 0; i--) {
    this->components.at(i)->update();
  }
}

void GameObject::render() {
  for (unsigned i = 0; i < this->components.size(); i++) {
    this->components.at(i)->render();
  }
}

void GameObject::addComponent(Component* component) {
  this->components.emplace_back(component);
}

void GameObject::removeComponent(const Component* component) {
  bool notFound = true;
  for (unsigned i = 0; i < this->components.size(); i++) {
    if (this->components.at(i).get() == component) {
      this->components.erase(this->components.begin() + i);
      notFound = false;
      break;
    }
  }
  if (notFound) {
    printf("The component to be removed could not be found.\n");
  }
}

Component* GameObject::getComponent(const string& type) {
  for (int i = this->components.size() - 1; i >= 0; i--) {
    if (this->components.at(i)->isType(type)) {
      return this->components.at(i).get();
    }
  }
  return nullptr;
}
