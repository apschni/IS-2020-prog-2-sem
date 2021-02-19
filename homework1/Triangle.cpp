#include "geometry.h"
#include <cmath>

Triangle::Triangle(int i, Point *point) : Polygon(i, point) {}
Triangle::Triangle(const Polygon &polygon) : Polygon(polygon) {}
Triangle::~Triangle() {

}

bool Triangle::hasRightAngle() const {
  std::vector<Point *> sides = calculateSides();
  double a = sqrt(pow(sides[0]->getX(),2) + pow(sides[0]->getY(),2));
  double b = sqrt(pow(sides[1]->getX(),2) + pow(sides[1]->getY(),2));
  double c = sqrt(pow(sides[2]->getX(),2) + pow(sides[2]->getY(),2));
  return ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (c * c + b * b == a * a));
}

