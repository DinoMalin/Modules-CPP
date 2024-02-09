#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form();
		Form(const Form &ref);
		Form(std::string name, bool _signed, int gradeToSign, int gradeToExecute);
		~Form();

		const Form& operator=(const Form& ref);

		const std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {return "Grade too high.";}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {return "Grade too low.";}
		};
};

std::ostream &operator<<(const std::ostream &flux, const Form &ref);