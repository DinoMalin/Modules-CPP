#pragma once
#include "Fixed.hpp"

class Point {
	private:
		Fixed x;
		Fixed y;
	public:
		Point();
		Point(const Point &point);
		Point(Fixed x, Fixed y);
		~Point();
		Point operator=(const Point &instance);
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);