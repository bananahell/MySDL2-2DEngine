#ifndef VEC2
#define VEC2

#define DEGREE_TO_RADIAN 180 / 3.14159265358979323846
#define RADIAN_TO_DEGREE 3.14159265358979323846 / 180

/**
 * Game's way of calculating 2D vector distances, scalings and rotations.
 * @author Pedro Nogueira
 */
class Vec2 {
 public:
  float posX;  // Horizontal position of `Vec2`.

  float posY;  // Vertical position of `Vec2`.

  /**
   * Default constructor starting in (0,0).
   */
  Vec2();

  /**
   * Constructor with starting position.
   * @param posX First horizontal position.
   * @param posY First vertical position.
   */
  Vec2(float, float);

  /**
   * Default destructor.
   */
  ~Vec2();

  /**
   * Way of adding two `Vec2`.
   * @param opInput Other `Vec2` to add to this one.
   * @return Resulting `Vec2`.
   */
  Vec2 operator+(const Vec2&) const;

  /**
   * Way of adding a value to `posX` and `posY`.
   * @param opInput Value to add.
   * @return Resulting `Vec2`.
   */
  Vec2 operator+(const float) const;

  /**
   * Way of subtracting two `Vec2`.
   * @param opInput Other `Vec2` to subtract to this one.
   * @return Resulting `Vec2`.
   */
  Vec2 operator-(const Vec2&) const;

  /**
   * Way of subtracting a value to `posX` and `posY`.
   * @param opInput Value to subtract.
   * @return Resulting `Vec2`.
   */
  Vec2 operator-(const float) const;

  /**
   * Multiplies posX and posY of both `Vec2`.
   * @param opInput Other `Vec2` to multiply to this one.
   * @return Resulting `Vec2`.
   */
  Vec2 operator*(const Vec2&) const;

  /**
   * Way of multiplying a value to `posX` and `posY`.
   * @param opInput Value to multiply.
   * @return Resulting `Vec2`.
   */
  Vec2 operator*(const float) const;

  /**
   * Divides posX and posY of both `Vec2`.
   * @param opInput Other `Vec2` to divide to this one.
   * @return Resulting `Vec2`.
   */
  Vec2 operator/(const Vec2&) const;

  /**
   * Way of dividing `posX` and `posY` by a value.
   * @param opInput Value to divide by.
   * @return Resulting `Vec2`.
   */
  Vec2 operator/(const float) const;

  /**
   * Rotate `Vec2` by radians.
   * @param angle Angle in radians.
   * @return Resulting `Vec2`.
   */
  Vec2 rotate(float);

  /**
   * Get difference of input to `posX`.
   * @param posX Value to compare.
   * @return Resulting `posX`.
   */
  float getDiffX(float);

  /**
   * Get difference of input to `posY`.
   * @param posX Value to compare.
   * @return Resulting `posY`.
   */
  float getDiffY(float);

  /**
   * Get distance of input to this `Vec2`.
   * @param pos Position to compare.
   * @return Resulting `Vec2`.
   */
  float getDiff(Vec2);

  /**
   * Get cosine with another `Vec2`.
   * @param pos Other `Vec2` to compare.
   * @return Resulting cosine.
   */
  float getCos(Vec2);

  /**
   * Get sine with another `Vec2`.
   * @param pos Other `Vec2` to compare.
   * @return Resulting sine.
   */
  float getSin(Vec2);

  /**
   * Get angle in radians to another `Vec2`.
   * @param pos Other `Vec2` to compare.
   * @return Resulting angle in radians.
   */
  float getAngle(Vec2);

  /**
   * Degree to radian converter.
   * @param angleIn Angle value in degrees.
   * @return Given angle in radians.
   */
  static float degreeToRadian(float);

  /**
   * Radian to degree converter.
   * @param angleIn Angle value in radians.
   * @return Given angle in degrees.
   */
  static float radianToDegree(float);

  /**
   * Project a vector using a distance and an angle in radians.
   * @param dist Distance of new vector.
   * @param angle Angle in radians of new vector.
   * @return Resulting `Vec2`.
   */
  static Vec2 project(float, float);
};

#endif  // VEC2
