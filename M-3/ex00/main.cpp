#include "ClapTrap.hpp"

int main() {
	ClapTrap clapOne("Dinozaur");

	clapOne.attack("Steve");
	clapOne.takeDamage(9);
	clapOne.beRepaired(2);
	clapOne.takeDamage(5);
	clapOne.attack("Steve");

	ClapTrap clapTwo("Robo");
	for (int i = 0; i < 12; i++)
		clapTwo.attack("Steve");
}