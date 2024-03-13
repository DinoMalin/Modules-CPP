#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
		sp.addNumber(4);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::vector<int> vect;
	for (int i = 0; i < 10000; i++) {
		vect.push_back(i);
	}

	Span sp2 = Span(10000);
	try {
		sp2.addRange(vect.begin(), vect.end());
		std::cout << "Range added." << std::endl;
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Span sp3 = Span(20);
	try {
		sp3.addRange(vect.begin(), vect.begin() + 30);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Span sp4 = Span(5);
	sp4.addNumber(1);
	try {
		std::cout << sp4.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << sp4.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}