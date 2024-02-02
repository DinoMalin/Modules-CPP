#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "A Dog was born."
			  << std::endl;
}
Dog::~Dog() {
	delete this->brain;
	std::cout << "A Dog died."
			  << std::endl;
}

Dog& Dog::operator=(const Dog &dog) {
	std::cout << "Dog copy !" << std::endl;
	this->type = dog.type;
	delete this->brain;
	this->brain = new Brain(*dog.brain);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Waf waf !" << std::endl;
}

void Dog::setName(std::string name) {
	this->name = name;
}

std::string Dog::getName() const {
	return this->name;
}