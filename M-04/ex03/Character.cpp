#include "Character.hpp"

Character::Character() : name("undefined") {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}
Character::Character(const std::string& name) : name(name) {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}
Character::Character(const Character& inst) {
	*this = inst;
}
Character& Character::operator=(const Character& inst) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
		if (inst.inventory[i])
			this->inventory[i] = inst.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	name = inst.name;
	return *this;
}
Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

void Character::equip(AMateria* materia) {
	int	i(0);
	while (this->inventory[i] && i < 4)
		i++;
	if (i != 4 && !this->inventory[i])
		this->inventory[i] = materia;
}

void Character::unequip(int idx) {
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
}

std::string const& Character::getName() const {
	return this->name;
}