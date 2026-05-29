#ifndef RECT
#define RECT

#include "Vec2.h"

/**
 * Way of defining and manipulating 2D space in game.
 * @author Pedro Nogueira
 */
class Rect {
 public:
  float posX;  // Top left horizontal position of `Rect`.

  float posY;  // Top left vecrtical position of `Rect`.

  float width;  // Width of `Rect`.

  float height;  // Height of `Rect`.

  /**
   * Default constructor starting in (0,0) with sizes (0,0).
   */
  Rect();

  /**
   * Constructor with starting values.
   * @param posX Top left horizontal position.
   * @param posY Top left vertical position.
   * @param width Width.
   * @param height Height.
   */
  Rect(float, float, float, float);

  /**
   * Default destructor.
   */
  ~Rect();

  /**
   * Set top left position.
   * @param posX Top left horizontal position.
   * @param posY Top left vertical position.
   */
  void setPos(float, float);

  /**
   * Set top left position.
   * @param pos `Vec2` top left position.
   */
  void setPos(Vec2);

  /**
   * Scale `Rect`.
   * @param width Width.
   * @param height Height.
   */
  void setSize(float, float);

  /**
   * Scale `Rect` to size with `Vec2`.
   * @param size `Vec2` used to measure.
   */
  void setSize(Vec2);

  /**
   * Set `Rect` position by choosing its center position.
   * @param posX Center horizontal position.
   * @param posY Center vertical position.
   */
  void setCenter(float, float);

  /**
   * Set `Rect` position by choosing its center position.
   * @param pos Center position with `Vec2`.
   */
  void setCenter(Vec2);

  /**
   * Checks if point is inside `Rect`.
   * @param xCoord Point horizontal position.
   * @param yCoord Point vertical position.
   * @return Whether if point is inside the `Rect`.
   */
  bool contains(float, float);

  /**
   * Checks if `Vec2` point is inside `Rect`.
   * @param position `Vec2` point position.
   * @return Whether if `Vec2` point is inside the `Rect`.
   */
  bool contains(Vec2);

  /**
   * Get top left position.
   * @return `Vec2` top left position.
   */
  Vec2 getPos();

  /**
   * Get `Rect` size.
   * @return `Rect` size in `Vec2` format.
   */
  Vec2 getSize();

  /**
   * Get center position.
   * @return `Vec2` center position.
   */
  Vec2 getCenter();
};

#endif  // RECT
