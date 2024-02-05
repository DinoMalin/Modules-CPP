#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : idx(0) {
	for (int i = 0; i < 4; i++) {
		this->materiaArray[i] = NULL;
	}
}
MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->materiaArray[i])
			delete this->materiaArray[i];
	}
}
MateriaSource::MateriaSource(const MateriaSource& inst) {
	*this = inst;
}
MateriaSource& MateriaSource::operator=(const MateriaSource& inst) {
	for (int i = 0; i < 4; i++) {
		if (this->materiaArray[i])
			delete this->materiaArray[i];
		if (inst.materiaArray[i])
			this->materiaArray[i] = inst.materiaArray[i]->clone();
		else
			this->materiaArray[i] = NULL;
	}
	this->idx = inst.idx;
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (!this->materiaArray[this->idx])
		this->materiaArray[this->idx] = materia;
	if (this->idx < 3)
		this->idx++;
}

AMateria* MateriaSource::createMateria(std::string const & type) { 
	int	i(3);
	while (i >= 0) {
		if (this->materiaArray[i] && this->materiaArray[i]->getType() == type)
			return this->materiaArray[i]->clone();
		i--;
	}
	return 0;
}