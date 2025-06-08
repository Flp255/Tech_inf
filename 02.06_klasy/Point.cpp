#include <iostream>
#include "Point.h"
int Point::m_numberOfPoints = 0;
Point::Point() {
    m_name = "bez nazwy";
    m_x = 0;
    m_y = 0;
    Point::m_numberOfPoints++;
}
Point::Point(const std::string& name, double x, double y) {
    m_name = name;
    m_x = x;
    m_y = y;
    Point::m_numberOfPoints++;
}
Point::~Point() {
    Point::m_numberOfPoints--;
}
…
int Point::numberOfPoints() {
    return Point::m_numberOfPoints;
}