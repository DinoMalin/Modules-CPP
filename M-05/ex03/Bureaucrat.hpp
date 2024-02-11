#pragma once
#include <string>
#include <iostream>

#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &ref);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		const Bureaucrat& operator=(const Bureaucrat &ref);

		const std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm& form);
		void executeForm(const AForm &form);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() { return "Grade too high."; }
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {return "Grade too low.";}
		};
};

std::ostream& operator<<(std::ostream& flux, const Bureaucrat &ref);