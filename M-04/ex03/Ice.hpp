#pragma once
#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		~Ice();
		Ice(const Ice &ice);
		void use(ICharacter& target);
		AMateria* clone() const;
};