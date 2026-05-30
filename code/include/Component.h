#ifndef COMPONENT
#define COMPONENT

#include <string>

#include "GameObject.h"

#define SPRITE_TYPE "Sprite"

/**
 * Stuff inside a game object, like its rendered sprite, sounds, etc.
 * @author Pedro Nogueira
 */
class Component {
 public:
  GameObject& parent;  // GameObject that contains this component.

  /**
   * Default constructor.
   * @param parent GameObject that contains this component.
   */
  explicit Component(GameObject&);

  /**
   * Default destructor.
   */
  virtual ~Component();

  /**
   * Renders visual component.
   */
  virtual void render();

  /**
   * Logic runner of the component.
   */
  virtual void update() = 0;

  /**
   * Gets class type that implements this component.
   * @return Class type of this component.
   */
  virtual std::string getType() = 0;

  /**
   * Compares class type that implements this component.
   * @param type Type to be compared with this component's own type.
   * @return Whether component types match.
   */
  virtual bool isType(const std::string&) = 0;
};

#endif  // COMPONENT
