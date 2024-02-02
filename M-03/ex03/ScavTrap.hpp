#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		~ScavTrap();
		void attack(const std::string &target);
		void guardGate();
};