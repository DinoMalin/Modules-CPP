#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "A cat was born."
			  << std::endl;
}
Cat::~Cat() {
	std::cout << "A cat died."
			  << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Miaou miaou !" << std::endl;
}