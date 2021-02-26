#include "geometry.h"
#include <cmath>

RegularPolygon::RegularPolygon(int i, Point *point) : Polygon(i, point) {}

RegularPolygon::RegularPolygon(const Polygon &polygon) : Polygon(polygon) {}

RegularPolygon::~RegularPolygon() {

}

double RegularPolygon::perimeter() const {
    std::vector<Point*> sides = calculateSides();
    double sidelenght = sqrt(sides[0]->getX() * sides[0]->getX()
            + sides[0]->getY() * sides[0]->getY());
    return n * sidelenght;
}

double RegularPolygon::area() const {
    std::vector<Point*> sides = calculateSides();
    double sidelenght = sqrt(sides[0]->getX() * sides[0]->getX()
            + sides[0]->getY() * sides[0]->getY());
    return n * sidelenght * sidelenght / (4 * tan(M_PI/n));
}