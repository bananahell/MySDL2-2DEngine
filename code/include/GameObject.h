#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <memory>
#include <string>
#include <vector>

#include "Rect.h"

class Component;

/**
 * What exists inside a game's state, being the stuff that act in the game.
 * @author Pedro Nogueira
 */
class GameObject {
 public:
  Rect box;  // Position and size of game object.

  std::vector<std::unique_ptr<Component>> components;  // Components in object.

  bool isAlive;  // Whether if game object should die.

  /**
   * Default constructor.
   */
  GameObject();

  /**
   * Default destructor.
   */
  ~GameObject();

  /**
   * Function that calls each of the game object's components updates.
   */
  void update();

  /**
   * Function that calls each of the game object's components renders.
   */
  void render();

  /**
   * Adds component to game object.
   * @param component Component to be added.
   */
  void addComponent(Component*);

  /**
   * Removes component from game object.
   * @param component Component to be removed.
   */
  void removeComponent(const Component*);

  /**
   * Removes all components from game object and sets isAlive to false.
   */
  void requestDelete();

  /**
   * Gets the component in game object by type.
   * @param type Type of component to get.
   * @return The component searched for.
   */
  Component* getComponent(const std::string&);
};

#endif  // GAMEOBJECT
