#include "Bureaucrat.hpp"

int main() {
	Bureaucrat steve("Steve", 3);
	Bureaucrat john("John", 148);

	for (int i(0); i < 3; i++) {
		try {
			steve.incrementGrade();
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << steve << std::endl;

	for (int i(0); i < 3; i++) {
		try {
			john.decrementGrade();
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << john << std::endl;

	try {
		Bureaucrat bob("bob", 0);
		std::cout << bob << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat james("james", 153);
		std::cout << james << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}