#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(const std::string &name);
		~FragTrap();
		void highFivesGuys();
};