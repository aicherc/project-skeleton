#ifndef RECTANGLE_H
#define RECTANGLE_H

namespace shapes {
  class Rectangle {
    public:
      int x0, y0, x1, y1;

      Rectangle(int x0=0, int y0=0, int x1=0, int y1=0);
      ~Rectangle();
      Rectangle operator+(const Rectangle& rect2);

      int getLength();
      int getHeight();
      int getArea();
      void move(int dx, int dy);
  }; // class Rectangle
} // namespace shapes

#endif
