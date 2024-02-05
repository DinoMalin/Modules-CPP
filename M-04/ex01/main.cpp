#include "Cat.hpp"
#include "Dog.hpp"

#define ARR_SIZE 4

int main()
{
	Animal* spa[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; i++) {
		if (i < ARR_SIZE / 2)
			spa[i] = new Dog();
		else
			spa[i] = new Cat();
	}

	spa[0]->makeSound();
	spa[ARR_SIZE - 1]->makeSound();

	for (int i = 0; i < ARR_SIZE; i++)
		delete spa[i];

	Dog medor;
	Dog sheldon;

	sheldon.setName("Sheldon");
	medor = sheldon;
	medor.setName("Medor");
	std::cout << medor.getName() << std::endl;
	std::cout << sheldon.getName() << std::endl;
	Dog medeux(medor);
	medeux.setName("Medeux");
	std::cout << medeux.getName() << std::endl;
}
