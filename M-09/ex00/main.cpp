#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./btc <input>" << std::endl;
		return 1;
	}
	BitcoinExchange be;

	try {
		be.fillData("data.csv");
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << " data.csv" << std::endl;
	}

	try {
		be.compare(av[1]);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << " " << av[1] << std::endl;
	}
}