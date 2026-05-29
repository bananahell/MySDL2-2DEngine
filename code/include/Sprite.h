#ifndef SPRITE
#define SPRITE

#include <SDL2/SDL_image.h>

#include <string>

#include "Component.h"

/**
 * A component used for showing a game object's visuals.
 * @author Pedro Nogueira
 */
class Sprite : public Component {
 public:
  SDL_Texture* texture;  // SDL texture of the sprite.

  int width;  // Sprite's width.

  int height;  // Sprite's height.

  SDL_Rect clipRect;  // SDL rectangle containing the sprite.

  /**
   * Default constructor. Just starts as nullptr.
   */
  explicit Sprite(GameObject&);

  /**
   * Constructor that already opens the image passed.
   * @param parent GameObject containing it.
   * @param fileName Name of the file with its directory.
   */
  explicit Sprite(GameObject&, const std::string&);

  /**
   * Destroys the texture of the sprite.
   */
  ~Sprite();

  /**
   * Opens the image passed.
   * @param fileName Name of the file with its directory.
   */
  void open(const std::string&);

  /**
   * Sets the dimensions of the rectangle in relation to the sprite's image.
   * @param posX Horizontal position of the rectangle's upper left corner.
   * @param posY Vertical position of the rectangle's upper left corner.
   * @param width Rectangle's width.
   * @param height Rectangle's height.
   */
  void setClip(int, int, int, int);

  /**
   * `[OVERRIDE]` Adds the sprite to the list of items to render.
   */
  void render() override;

  /**
   * `[OVERRIDE]` Updates sprite.
   */
  void update() override;

  /**
   * `[OVERRIDE]` Gets the `SPRITE` type.
   * @return The `SPRITE` type.
   */
  std::string getType() override;

  /**
   * `[OVERRIDE]` Compares input param with `SPRITE` type.
   * @param type Input type to compare with `SPRITE`.
   * @return Whether the type input is really `SPRITE`.
   */
  bool isType(const std::string&) override;
};

#endif  // SPRITE
