#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const Point &point) : x(point.getX()), y(point.getY()) {}
Point::Point(Fixed x, Fixed y) : x(x), y(y) {}
Point::~Point() {}

Point Point::operator=(const Point &instance) {
	this->x = instance.getX();
	this->y = instance.getY();
	return *this;
}

Fixed Point::getX(void) const {
	return this->x;
}
Fixed Point::getY(void) const {
	return this->y;
}