#ifndef UNTITLED1__GEOMETRY_H_
#define UNTITLED1__GEOMETRY_H_

#include <vector>
class Point {
 private:
  double x;
  double y;

 public:
  Point(const double, const double);
  Point();
  Point(const Point &);
  virtual ~Point();

  Point &operator=(const Point &);

  double getX() const;
  double getY() const;
};

class PolygonalChain {
 protected:
  int n;
  Point *points;
 public:
  PolygonalChain(int n, Point *);
  PolygonalChain(const PolygonalChain &);
  PolygonalChain &operator=(const PolygonalChain &);
  virtual ~PolygonalChain();

  virtual double perimeter() const;
  long getN() const;
  Point getPoint(int i) const;
 protected:
  virtual std::vector<Point *> calculateSides() const;
};

class ClosedPolygonalChain : public PolygonalChain {
 public:
  ClosedPolygonalChain(int, Point *);
  virtual ~ClosedPolygonalChain();
  ClosedPolygonalChain(const ClosedPolygonalChain &);
  virtual double area() const;
 protected:
  std::vector<Point *> calculateSides() const override;
};

class Polygon : public ClosedPolygonalChain {
 public:
  Polygon(int, Point *);
  Polygon(const Polygon &);
  virtual ~Polygon();
};

class Triangle : public Polygon{
 public:
  Triangle(int i, Point *point);
  Triangle(const Polygon &polygon);
  virtual ~Triangle();
  bool hasRightAngle() const;
};

class Trapezoid : public Polygon {
 public:
  Trapezoid(int, Point *);
  Trapezoid(const Trapezoid &);
  virtual ~Trapezoid();
  double height() const;
};

class RegularPolygon : public Polygon{
 public:
  RegularPolygon(int i, Point *point);
  RegularPolygon(const Polygon &polygon);
  virtual ~RegularPolygon();
  virtual double perimeter() const override;
  virtual double area() const override;

private:
    Point * calculateOneSide() const;
};
#endif
