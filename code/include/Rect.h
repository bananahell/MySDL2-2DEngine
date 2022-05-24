#ifndef RECT
#define RECT

#include "Vec2.h"

class Rect {
 public:
  Rect();
  Rect(float, float, float, float);
  ~Rect();

  void setPos(float, float);
  void setPos(Vec2);
  void setSize(float, float);
  void setSize(Vec2);
  void setCenter(float, float);
  void setCenter(Vec2);
  bool contains(float, float);
  bool contains(Vec2);
  Vec2 getPos();
  Vec2 getSize();
  Vec2 getCenter();

  float posX;
  float posY;
  float width;
  float height;
};

#endif  // RECT
