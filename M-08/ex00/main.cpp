#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int main() {
	std::vector<int> vect(5, 0);
	std::deque<int> deq(5, 0);

	std::list<int> list;

	for (int i = 0; i < 5; i++) {
		vect[i] = i;
		deq[i] = i;
		list.push_back(i);
	}

	try {
		std::cout << *easyfind(vect, 4) << std::endl;
		std::cout << *easyfind(deq, 4) << std::endl;
		std::cout << *easyfind(list, 4) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << *easyfind(vect, 8) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << *easyfind(deq, 8) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << *easyfind(list, 8) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}