#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(10) {}
ClapTrap::ClapTrap(const ClapTrap &inst) {*this = inst;}
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " has been destroyed." << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(10) {
	std::cout << "ClapTrap " << this->name << " has been called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &inst) {
	this->name = inst.getName();
	this->hitPoints = inst.getHitPoints();
	this->energyPoints = inst.getEnergyPoints();
	this->attackDamage = inst.getAttackDamage();
	return *this;
}

std::string ClapTrap::getName() const {
	return this->name;
}
int	ClapTrap::getHitPoints() const {
	return this->hitPoints;
}
int	ClapTrap::getEnergyPoints() const {
	return this->energyPoints;
}
int	ClapTrap::getAttackDamage() const {
	return this->attackDamage;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		std::cout << "ClapTrap " << this->name
				<< " attacks " << target << ", causing "
				<< this->attackDamage << " points of damage!"
				<< std::endl;
		this->energyPoints--;
	} else if (this->hitPoints <= 0) {
		std::cout << "ClapTrap " << this->name
				  << " is dead, he can't attack anymore."
				  << std::endl;
	} else {
		std::cout << "ClapTrap " << this->name
			<< " has no more energy, he can't attack anymore."
			<< std::endl;
	}
}
void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->name
			  << " takes " << amount << " damages!";
	if (this->hitPoints > 0)
		this->hitPoints -= amount;
	else
		std::cout << " But he's already dead!";
	std::cout << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		std::cout << "ClapTrap " << this->name
				<< " get " << amount << " health points back!"
				<< std::endl;
		this->hitPoints += amount;
		this->energyPoints--;
	} else if (this->hitPoints <= 0) {
		std::cout << "ClapTrap " << this->name
				  << " is dead, he can't repair himself anymore."
				  << std::endl;
	} else {
		std::cout << "ClapTrap " << this->name
			<< " has no more energy, he can't repair himself anymore."
			<< std::endl;
	}
}