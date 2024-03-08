#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage : ./scalar <literal>" << std::endl;
		return 0;
	}
	ScalarConverter::convert(av[1]);
}