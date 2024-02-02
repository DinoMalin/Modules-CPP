#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *brain;
		std::string name;
	public:
		Dog();
		~Dog();
		void makeSound() const;
		void setName(std::string name);
		Dog &operator=(const Dog &animal);
		std::string getName() const;
};