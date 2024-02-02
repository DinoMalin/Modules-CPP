#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}
FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " has been called." << std::endl;
}
FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys() {
		if (this->hitPoints > 0 && this->energyPoints > 0) {
		std::cout << "FragTrap " << this->name
				<< " wants to do a high five !"
				<< std::endl;
		this->energyPoints--;
	} else if (this->hitPoints <= 0) {
		std::cout << "FragTrap " << this->name
				  << " is dead, he can't high five anymore."
				  << std::endl;
	}
}