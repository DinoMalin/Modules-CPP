#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(const std::string &name);
		~FragTrap();
		void highFivesGuys();
};