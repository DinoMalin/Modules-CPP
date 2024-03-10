#include "RPN.hpp"
#include <queue>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Usage: ./RPN <expression>" << std::endl;
		return 1;
	}

	try {
		RPN rpn(av[1]);
		double result = rpn.getResult();
		std::cout << result << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}