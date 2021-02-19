#include "geometry.h"

RegularPolygon::RegularPolygon(int i, Point *point) : Polygon(i, point) {}
RegularPolygon::RegularPolygon(const Polygon &polygon) : Polygon(polygon) {}
RegularPolygon::~RegularPolygon() {

}
