#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"

std::string test() {
	throw std::out_of_range("test");
	return "oui";
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage : ./btc <input>" << std::endl;
		return 1;
	}
	BitcoinExchange be;

	std::string fileName("data.csv");
	try {
		be.fillData(fileName);
		fileName = std::string(av[1]);
		be.fillInput(fileName);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << " " << fileName << std::endl;
	}

	be.compare();
}