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
   * `[VIRTUAL]` Default destructor.
   */
  virtual ~Component();

  /**
   * `[VIRTUAL]` Renders visual component.
   */
  virtual void render();

  /**
   * `[PURE VIRTUAL]` Logic runner of the component.
   */
  virtual void update() = 0;

  /**
   * `[PURE VIRTUAL]` Gets class type that implements this component.
   * @return Class type of this component.
   */
  virtual std::string getType() = 0;

  /**
   * `[PURE VIRTUAL]` Compares class type that implements this component.
   * @param type Type to be compared with this component's own type.
   * @return Whether component types match.
   */
  virtual bool isType(const std::string&) = 0;
};

#endif  // COMPONENT
