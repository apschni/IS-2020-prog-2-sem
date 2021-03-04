#include "geometry.h"
#include <cmath>
#include <vector>

PolygonalChain::PolygonalChain(int n, Point *a) {
  Point *copiedArray = new Point[n];
  for (int i = 0; i < n; ++i) {
    copiedArray[i] = a[i];
  }
  this -> points = copiedArray;
  this -> n = n;
}
PolygonalChain::PolygonalChain(const PolygonalChain &other) : n(other.n), points(other.points) {}
//u should do smth - what can i do there??
PolygonalChain::~PolygonalChain() = default;

PolygonalChain &PolygonalChain::operator=(const PolygonalChain &other) = default;


std::vector<Point *> PolygonalChain::calculateSides() const {
  std::vector<Point *> sides;
  sides.reserve(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    sides.push_back(new Point(points[i + 1].getX() - points[i].getX(),
                              points[i + 1].getY() - points[i].getY()));
  }
  return sides;
}

double PolygonalChain::perimeter() const {
  double perimeter = 0;
  std::vector<Point *> sides = this->calculateSides();

  for (Point *side : sides) {
    perimeter += sqrt(pow(side->getX(), 2) + pow(side->getY(), 2));
  }
  return perimeter;
}

long PolygonalChain::getN() const {
  return n;
}

Point PolygonalChain::getPoint(int i) const {
  return points[i];
}