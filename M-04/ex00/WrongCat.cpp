#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "A WrongCat was born."
			  << std::endl;
}
WrongCat::~WrongCat() {
	std::cout << "A WrongCat died."
			  << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Miaou miaou !" << std::endl;
}