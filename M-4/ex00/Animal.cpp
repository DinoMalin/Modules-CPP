#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "An animal was born."
			  << std::endl;
}
Animal::Animal(const Animal &animal) {
	*this = animal;
	std::cout << "An animal was born."
			  << std::endl;
}
Animal::~Animal() {
		std::cout << "An animal died."
			  << std::endl;
}
Animal& Animal::operator=(const Animal &animal) {
	this->type = animal.getType();
	return *this;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "Mamma mia !" << std::endl;
}