#ifndef SPRITE
#define SPRITE

#include <SDL2/SDL_image.h>

#include <string>

class Sprite {
 public:
  SDL_Texture* texture;  // SDL texture of the sprite.
  int width;             // Sprite's width.
  int height;            // Sprite's height.
  SDL_Rect clipRect;     // SDL rectangle containing the sprite.

  /**
   * Default constructor. Just starts as nullptr.
   */
  Sprite();
  /**
   * Constructor that already opens the image passed.
   * @param fileName Name of the file with its directory.
   */
  explicit Sprite(std::string);
  /**
   * Destroys the texture of the sprite.
   */
  ~Sprite();
  /**
   * Opens the image passed.
   * @param fileName Name of the file with its directory.
   */
  void open(std::string);
  /**
   * Sets the dimensions of the rectangle in relation to the sprite's image.
   * @param posX Horizontal position of the rectangle's upper left corner.
   * @param posY Vertical position of the rectangle's upper left corner.
   * @param width Rectangle's width.
   * @param height Rectangle's height.
   */
  void setClip(int, int, int, int);
  /**
   * Adds the sprite to the list of items the renderer needs to show.
   * @param posX Horizontal position of the rectangle's upper left corner.
   * @param posY Vertical position of the rectangle's upper left corner.
   */
  void render(int, int);
};

#endif  // SPRITE
