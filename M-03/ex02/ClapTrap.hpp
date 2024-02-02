#pragma once
#include <iostream>
#include <string>

class ClapTrap {
	protected:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &inst);
		ClapTrap(const std::string &name);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &inst);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName() const;
		int			getHitPoints() const;
		int			getEnergyPoints() const;
		int			getAttackDamage() const;
};