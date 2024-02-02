#pragma once
#include <string>
#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &Wronganimal);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &Wronganimal);
		std::string getType() const;
		void makeSound() const;
};