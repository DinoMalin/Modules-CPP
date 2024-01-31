#include "Point.hpp"



int main ( void ) {
	if ( bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15)) == true )
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;

	if ( bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(30, 15)) == true )
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;

	if ( bsp(Point(1, 1), Point(2, 3), Point(3, 2), Point(2, 2)) == true )
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;

	if ( bsp(Point(1, 1), Point(2, 3), Point(3, 2), Point(2.5f, 2.5f)) == true )
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;
	return 0;
}