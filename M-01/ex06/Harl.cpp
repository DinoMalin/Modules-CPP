#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "Debugosaurus Rex" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Infosaurus Armatus" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void)  {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Warningatops horridus" << std::endl;
	std::cout << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Errociraptor mongoliensis" << std::endl;
	std::cout << std::endl;
}

void	Harl::filter(std::string level) {
	int	i(0);
	std::string	debug_levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4 && level != debug_levels[i])
		i++;
	switch (i)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}