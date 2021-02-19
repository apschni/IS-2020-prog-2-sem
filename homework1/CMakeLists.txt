cmake_minimum_required(VERSION 3.17)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 main.cpp Point.cpp geometry.h PolygonalChain.cpp ClosedPolygonalChain.cpp Polygon.cpp Trapezoid.cpp Triangle.cpp RegularPolygon.cpp)