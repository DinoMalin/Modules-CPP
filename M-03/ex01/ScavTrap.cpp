#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " has been called." << std::endl;
}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " has been destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		std::cout << "ScavTrap " << this->name
				<< " attacks " << target << ", causing "
				<< this->attackDamage << " points of damage!"
				<< std::endl;
		this->energyPoints--;
	} else if (this->hitPoints <= 0) {
		std::cout << "ScavTrap " << this->name
				  << " is dead, he can't attack anymore."
				  << std::endl;
	} else {
		std::cout << "ScavTrap " << this->name
			<< " has no more energy, he can't attack anymore."
			<< std::endl;
	}
}

void ScavTrap::guardGate() {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		std::cout << "ScavTrap " << this->name
				<< " activated Gate keeper mode."
				<< std::endl;
		this->energyPoints--;
	} else if (this->hitPoints <= 0) {
		std::cout << "ScavTrap " << this->name
				  << " is dead, he can't activate Gate keeper anymore."
				  << std::endl;
	}
}
