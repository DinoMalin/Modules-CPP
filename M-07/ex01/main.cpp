#include "iter.hpp"
#include <string>

int main() {
	int intArr[] = {4, 2, 1, 5};
	std::string strArr[] = {"Dinosaure", "Malin", "Et", "Cool"};

	iter(intArr, 4, print);
	std::cout << std::endl;
	iter(strArr, 4, print);
}