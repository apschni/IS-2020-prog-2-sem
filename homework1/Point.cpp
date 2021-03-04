#include "geometry.h"

Point::Point(const double x, const double y) : x(x), y(y) {}
Point::Point() : x(0.0), y(0.0) {}
Point::Point(const Point &other) : x(other.x), y(other.y) {}
Point::~Point() = default;

Point &Point::operator=(const Point &rhs) {
  if (this == &rhs) {
    return *this;
  }
  x = rhs.x;
  y = rhs.y;
  return *this;
}

double Point::getX() const {
  return x;
}

double Point::getY() const {
  return y;
}


