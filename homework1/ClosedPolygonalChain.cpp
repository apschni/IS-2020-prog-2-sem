#include "geometry.h"
#include <cmath>

ClosedPolygonalChain::ClosedPolygonalChain(int n, Point *a) : PolygonalChain(n, a) {}
ClosedPolygonalChain::ClosedPolygonalChain(const ClosedPolygonalChain &other)
  : PolygonalChain(other) {}
ClosedPolygonalChain::~ClosedPolygonalChain() = default;


std::vector<Point *> ClosedPolygonalChain::calculateSides() const {
  //copy-paste - fixed
  std::vector<Point *> sides = PolygonalChain::calculateSides(); //fixed copy-paste
  sides.push_back(new Point(points[0].getX() - points[n - 1].getX(),
                            points[0].getY() - points[n - 1].getY()));
  return sides;
}

double ClosedPolygonalChain::area() const {
  double area = 0;
  for (unsigned i = 0; i < n - 1; ++i) {
    area += ((((points + i)->getX()) * (points + i + 1)->getY())
          - (((points + i + 1)->getX()) * (points + i)->getY()));
  }
  area += points[n - 1].getX() * points[0].getY() - points[n - 1].getY() * points[0].getX();
  return std::abs(area)/2;
}
