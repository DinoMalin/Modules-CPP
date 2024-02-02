#include "Animal.hpp"

Animal::Animal() : type("Animal") {}
Animal::Animal(const Animal &animal) {
	*this = animal;
	std::cout << "A " << this->type
			  << " was born."
			  << std::endl;
}
Animal::~Animal() {
		std::cout << "A " << this->type
			  << " died."
			  << std::endl;
}
Animal& Animal::operator=(const Animal &animal) {
	this->type = animal.getType();
}

std::string Animal::getType() const {
	return this->type;
}