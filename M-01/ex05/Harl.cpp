#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "Debugosaurus Rex" << std::endl;
}

void Harl::info(void) {
	std::cout << "Infosaurus Armatus" << std::endl;
}

void Harl::warning(void)  {
	std::cout << "Warningatops horridus" << std::endl;
}

void Harl::error(void) {
	std::cout << "Errociraptor mongoliensis" << std::endl;
}

void Harl::complain(std::string level) {
	std::string	debug_levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	t_func		funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++) {
		if (level == debug_levels[i])
			(this->*funcs[i])();
	}
}