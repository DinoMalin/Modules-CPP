#pragma once
#include "AForm.hpp"
#include <cstdlib>
#include <fstream>
#include <ctime>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);

		void execute(const Bureaucrat& executor) const;
};