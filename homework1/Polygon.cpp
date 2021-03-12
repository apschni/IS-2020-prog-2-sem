#include "geometry.h"

Polygon::Polygon(int n, Point *a) : ClosedPolygonalChain(n, a){}
Polygon::Polygon(const Polygon &other) : ClosedPolygonalChain(other){}
Polygon::~Polygon() = default;
