#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	private:
		AMateria *inventory[4];
		std::string name;
	public:
		Character();
		Character(const Character& inst);
		Character(const std::string& name);
		~Character();

		Character& operator=(const Character& inst);
		std::string const & getName() const;

		void equip(AMateria* materia);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};