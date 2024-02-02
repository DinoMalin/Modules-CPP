#include "Zombie.hpp"

int main(void)
{
	Zombie *elizombie;

	elizombie = newZombie("Elizombie");
	elizombie->announce();
	randomChump("Maximort");
	delete elizombie;
}