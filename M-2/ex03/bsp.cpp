#include "Point.hpp"

Fixed	vectorialProduct(Point const a, Point const b, Point const point) {
	return (a.getX() - point.getX()) * (b.getY() - point.getY()) - (a.getY() - point.getY()) * (b.getX() - point.getX());
}

bool	sameSign(Fixed a, Fixed b, Fixed c) {
	if ((a < 0 && b < 0 && c < 0) || (a >= 0 && b >= 0 && c >= 0))
		return true;
	else
		return false;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed productAMB = vectorialProduct(a, b, point);
	Fixed productBMC = vectorialProduct(b, c, point);
	Fixed productCMA = vectorialProduct(c, a, point);
	return sameSign(productAMB, productBMC, productCMA);
}
