#include "Zombie.hpp"

int main ()
{
	int		armySize(5);
	Zombie	*horde(zombieHorde(armySize, "Soldier"));
	for (int i = 0; i < armySize; i++)
		horde[i].announce();
}