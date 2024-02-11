#pragma once
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:
		AForm *createSC(const std::string &target);
		AForm *createRR(const std::string &target);
		AForm *createPP(const std::string &target);
	public:
		Intern();
		Intern(const Intern &ref);
		~Intern();

		const Intern &operator=(const Intern &ref);

		AForm *makeForm(const std::string &name, const std::string &target);
};