#ifndef VEC2
#define VEC2

class Vec2 {
 public:
  Vec2();
  Vec2(float, float);
  ~Vec2();

  Vec2 operator+(const Vec2&) const;
  Vec2 operator+(const float) const;
  Vec2 operator-(const Vec2&) const;
  Vec2 operator-(const float) const;
  Vec2 operator*(const Vec2&) const;
  Vec2 operator*(const float) const;
  Vec2 operator/(const Vec2&) const;
  Vec2 operator/(const float) const;

  Vec2 rotate(float);
  float getDiffX(float);
  float getDiffY(float);
  float getDiff(Vec2);
  float getCos(Vec2);
  float getSin(Vec2);
  float getAngle(Vec2);
  static float cos(float);
  static float sin(float);
  static Vec2 project(float, float);

  float posX;
  float posY;
};

#endif  // VEC2
