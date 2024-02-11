#include "Intern.hpp"

Intern::Intern() {};
Intern::Intern(const Intern &ref) {(void)ref;};
Intern::~Intern() {};

const Intern& Intern::operator=(const Intern &ref) {(void)ref; return *this;}

AForm* Intern::createSC(const std::string &target) {
	return new ShrubberyCreationForm(target);
}
AForm* Intern::createRR(const std::string &target) {
	return new RobotomyRequestForm(target);
}
AForm* Intern::createPP(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
	const std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (Intern::*constructors[])(const std::string&) = {
		&Intern::createSC,
		&Intern::createRR,
		&Intern::createPP
	};
	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << name << "." << std::endl;
			return (this->*constructors[i])(target);
		}
	}
	std::cout << "Intern could not create " << name << " : Name not recognized." << std::endl;
	return NULL;
}