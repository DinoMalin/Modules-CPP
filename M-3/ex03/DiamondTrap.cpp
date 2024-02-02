#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap() {
	this->name = "unnamed";
	this->ClapTrap::name = this->name + "_clap_name";
	FragTrap::hitPoints = 100;
	ScavTrap::energyPoints = 50;
	FragTrap::attackDamage = 30;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
	this->name = name;
	this->ClapTrap::name = name + "_clap_trap";

	FragTrap::hitPoints = 100;
	ScavTrap::energyPoints = 50;
	FragTrap::attackDamage = 30;
	std::cout << "DiamondTrap " << this->name << " has been called." << std::endl;
}
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " has been destroyed." << std::endl;
}
void DiamondTrap::whoAmI() {
	std::cout << "Diamond Trap : I am " << this->name
			  << ", but I am also " << this->ClapTrap::name
			  << std::endl;
}