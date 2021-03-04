#include "geometry.h"
#include <cmath>
#include <iostream>

Trapezoid::Trapezoid(int n, Point *a) : Polygon(n, a) {}
Trapezoid::Trapezoid(const Trapezoid &other) : Polygon(other) {}
Trapezoid & Trapezoid::operator=(const Trapezoid &) = default;
Trapezoid::~Trapezoid() = default;

double Trapezoid::height() const {
  std::vector<Point *> sides = calculateSides();
  double a = sqrt(pow(sides[1]->getX(), 2) + pow(sides[1]->getY(), 2));
  double b = sqrt(pow(sides[3]->getX(), 2) + pow(sides[3]->getY(), 2));
  return 2 * area() / (a + b);
}
