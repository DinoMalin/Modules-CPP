#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &ice) : AMateria("ice") {
	*this = ice;
}
Ice::~Ice() {}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at "
			  << target.getName() << " *"
			  << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}