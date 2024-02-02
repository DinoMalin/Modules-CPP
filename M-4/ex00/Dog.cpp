#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << "A dog was born."
			  << std::endl;
}
Dog::~Dog() {
	std::cout << "A dog died."
			  << std::endl;
}
void Dog::makeSound() const {
	std::cout << "Waf waf !" << std::endl;
}