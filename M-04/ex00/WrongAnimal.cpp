#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {}
WrongAnimal::WrongAnimal(const WrongAnimal &Wronganimal) {
	*this = Wronganimal;
	std::cout << "A WrongAnimal was born."
			  << std::endl;
}
WrongAnimal::~WrongAnimal() {
		std::cout << "A WrongAnimal died."
			  << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &Wronganimal) {
	this->type = Wronganimal.getType();
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Mamma mia !" << std::endl;
}