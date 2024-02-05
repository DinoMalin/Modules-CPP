#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		~Cure();
		Cure(const Cure &cure);
		void use(ICharacter& target);
		AMateria* clone() const;
};