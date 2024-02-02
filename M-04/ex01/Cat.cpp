#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "A Cat was born."
			  << std::endl;
}
Cat::~Cat() {
	delete this->brain;
	std::cout << "A Cat died."
			  << std::endl;
}

Cat& Cat::operator=(const Cat &cat) {
	std::cout << "Cat copy !" << std::endl;
	this->type = cat.type;
	delete this->brain;
	this->brain = new Brain(*cat.brain);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Miaou miaou !" << std::endl;
}

void Cat::setName(std::string name) {
	this->name = name;
}

std::string Cat::getName() const {
	return this->name;
}
