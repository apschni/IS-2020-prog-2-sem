#include "geometry.h"

Triangle::Triangle(int i, Point *point) : Polygon(i, point) {}
Triangle::Triangle(const Polygon &polygon) : Polygon(polygon) {}
Triangle & Triangle::operator=(const Triangle &triangle) = default;
Triangle::~Triangle() = default;

bool Triangle::hasRightAngle() const {
  std::vector<Point *> sides = calculateSides();
  for (Point *side1 : sides) {
    for (Point *side2 : sides) {
      if (side1->getX() * side2->getX() + side1->getY() * side2->getY() == 0){
        return true;
      }
    }
  }
  return false;
}

