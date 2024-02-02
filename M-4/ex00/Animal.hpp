#pragma once
#include <string>
#include <iostream>

class Animal {
	private:
		std::string type;
	public:
		Animal();
		Animal(const Animal &animal);
		~Animal();
		Animal &operator=(const Animal &animal);
		std::string getType() const;
};