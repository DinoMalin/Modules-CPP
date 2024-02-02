#include "FragTrap.hpp"

int main() {
	FragTrap clapOne("Dinozaur");

	clapOne.attack("Steve");
	clapOne.takeDamage(90);
	clapOne.beRepaired(20);
	clapOne.takeDamage(50);
	clapOne.attack("Steve");

	FragTrap clapTwo("Robo");
	for (int i = 0; i < 3; i++)
		clapTwo.attack("Steve");
	clapTwo.highFivesGuys();
}