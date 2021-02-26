#include "geometry.h"
#include <cmath>
#include <iostream>

ClosedPolygonalChain::ClosedPolygonalChain(int n, Point *a) : PolygonalChain(n, a) {}
ClosedPolygonalChain::ClosedPolygonalChain(const ClosedPolygonalChain &other)
  : PolygonalChain(other) {}
ClosedPolygonalChain::~ClosedPolygonalChain() {

}


std::vector<Point *> ClosedPolygonalChain::calculateSides() const {
  //copy-paste
  std::vector<Point *> sides;
  sides.reserve(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    sides.push_back(new Point(points[i + 1].getX() - points[i].getX(),
                              points[i + 1].getY() - points[i].getY()));
  }
  sides.push_back(new Point(points[0].getX() - points[n - 1].getX(),
                            points[0].getY() - points[n - 1].getY()));

  return sides;
}

double ClosedPolygonalChain::area() const {
  double area = 0;
  for (int i = 0; i < n - 1; ++i) {
    area += ((((points + i)->getX()) * (points + i + 1)->getY())
          - (((points + i + 1)->getX()) * (points + i)->getY()));
  }
  area += points[n - 1].getX() * points[0].getY() - points[n - 1].getY() * points[0].getX();
  return std::abs(area)/2;
}
