#pragma once
#include <string>
#include <iostream>

class Zombie {
	private:
		std::string _name;
	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void setName(std::string name);
		void announce(void);
};

Zombie* zombieHorde(int n, std::string name);