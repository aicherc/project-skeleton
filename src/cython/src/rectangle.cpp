#include "rectangle.h"

namespace shapes {

  Rectangle::Rectangle(int X0, int Y0, int X1, int Y1){
    x0 = X0;
    y0 = Y0;
    x1 = X1;
    y1 = Y1;
  }

  Rectangle::~Rectangle() { }

  Rectangle Rectangle::operator+(const Rectangle& rect2){
    Rectangle rect = Rectangle(0, 0, 0, 0);
    rect.x0 = this->x0 + rect2.x0;
    rect.y0 = this->y0 + rect2.y0;
    rect.x1 = this->x1 + rect2.x1;
    rect.y1 = this->y1 + rect2.y1;
    return rect;
  }

  int Rectangle::getLength() {
    return (x1 - x0);
  }

  int Rectangle::getHeight() {
    return (y1 - y0);
  }

  int Rectangle::getArea() {
    return (x1 - x0) * (y1 - y0);
  }

  void Rectangle::move(int dx, int dy) {
    x0 += dx;
    y0 += dy;
    x1 += dx;
    y1 += dy;
  }

}
