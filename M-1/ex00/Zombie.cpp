#include "Zombie.hpp"

Zombie::Zombie() {this->name = "";}

Zombie::Zombie(std::string name) {this->name = name;}

Zombie::~Zombie() {
	std::cout << this->name << ": AaaAAhh... I'm dying again...!" << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}