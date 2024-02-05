#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *brain;
		std::string name;
	public:
		Cat();
		Cat(const Cat &cat);
		~Cat();
		void makeSound() const;
		void setName(std::string name);
		Cat &operator=(const Cat &animal);
		std::string getName() const;
};