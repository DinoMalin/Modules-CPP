#pragma once
#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		~Cat();
		void makeSound() const;
};