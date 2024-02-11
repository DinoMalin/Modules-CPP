#include "Intern.hpp"

int main() {
	Intern intern;
	Bureaucrat john("John", 1);
	AForm *sc = intern.makeForm("shrubbery creation", "tree");
	AForm *rr = intern.makeForm("robotomy request", "Cat");
	AForm *pp = intern.makeForm("presidential pardon", "Dino");
	AForm *unknown = intern.makeForm("Nothing", "Dino");


	john.signForm(*sc);
	john.signForm(*rr);
	john.signForm(*pp);

	john.executeForm(*sc);
	john.executeForm(*rr);
	john.executeForm(*pp);

	delete sc;
	delete rr;
	delete pp;
	if (unknown)
		delete unknown;
}