#include "DiamondTrap.hpp"

int main() {
	DiamondTrap diamondOne("Dinozaur");

	diamondOne.attack("Steve");
	diamondOne.takeDamage(90);
	diamondOne.beRepaired(20);
	diamondOne.takeDamage(50);
	diamondOne.attack("Steve");

	DiamondTrap diamondTwo("Robo");
	for (int i = 0; i < 3; i++)
		diamondTwo.attack("Steve");
	diamondTwo.whoAmI();
}