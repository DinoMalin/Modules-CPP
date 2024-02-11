#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

/* Test :

Execute :
	PP
	RR
	SC
Execute foiré :
	PP
	RR
	SC

*/

int main() {
	Bureaucrat steve("Steve", 3);
	Bureaucrat john("John", 148);

	RobotomyRequestForm rr("Cat");
	PresidentialPardonForm pp("Dino");
	ShrubberyCreationForm sc("tree");

	/* Error : Form not signed. */
	steve.executeForm(rr);
	steve.executeForm(pp);
	steve.executeForm(sc);

	/* Error : Grade too low. */
	john.signForm(rr);
	john.signForm(pp);
	john.signForm(sc);

	/* Sucess */
	steve.signForm(rr);
	steve.signForm(pp);
	steve.signForm(sc);

	/* Error : Grade too low.*/
	john.executeForm(rr);
	john.executeForm(pp);
	john.executeForm(sc);

	/* Sucess */
	steve.executeForm(rr);
	steve.executeForm(pp);
	steve.executeForm(sc);
}