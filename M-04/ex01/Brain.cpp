#include "Brain.hpp"

Brain::Brain() {
	std::cout << "A Brain was created."
			  << std::endl;
}
Brain::Brain(const Brain &Brain) {
	*this = Brain;
	std::cout << "A Brain was created."
			  << std::endl;
}
Brain::~Brain() {
		std::cout << "A Brain was destroyed."
			  << std::endl;
}
Brain& Brain::operator=(const Brain &brain) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return *this;
}