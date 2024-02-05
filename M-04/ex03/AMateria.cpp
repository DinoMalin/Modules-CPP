#include "AMateria.hpp"

AMateria::AMateria() : _type("Air") {}
AMateria::~AMateria() {}
AMateria::AMateria(const AMateria &inst) {
	*this = inst;
}
AMateria::AMateria(std::string const &type) : _type(type) {}
AMateria& AMateria::operator=(const AMateria &inst) {
	this->_type = inst.getType();
	return *this;
}

std::string const& AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "Material of type " << this->_type
			  << " used on " << target.getName()
			  << std::endl;
}