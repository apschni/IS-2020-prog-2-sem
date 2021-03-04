#include "geometry.h"
#include <cmath>

RegularPolygon::RegularPolygon(int i, Point *point) : Polygon(i, point) {}

RegularPolygon::RegularPolygon(const Polygon &polygon) : Polygon(polygon) {}

RegularPolygon & RegularPolygon::operator=(const RegularPolygon &) = default;

RegularPolygon::~RegularPolygon() = default;

Point * RegularPolygon::calculateOneSide() const {
    return new Point(points[1].getX() - points[0].getX(),
                     points[1].getY() - points[0].getY());
}

double RegularPolygon::perimeter() const {
    Point *side = calculateOneSide();    //now i calculate only one side
    //all of em? - fixed
    double sidelenght = sqrt(side->getX() * side->getX()
            + side->getY() * side->getY());
    return n * sidelenght;
}

double RegularPolygon::area() const {
    Point *side = calculateOneSide();
    double sidelenght = sqrt(side->getX() * side->getX()
                             + side->getY() * side->getY());
    return n * sidelenght * sidelenght / (4 * tan(M_PI/n));
}