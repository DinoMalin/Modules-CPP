#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		AForm();
		AForm(const AForm &ref);
		AForm(std::string name, bool _signed, int gradeToSign, int gradeToExecute);
		virtual ~AForm();

		const AForm& operator=(const AForm& ref);

		const std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {return "Grade too high.";}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {return "Grade too low.";}
		};
		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw() {return "Form not signed.";}
		};
};

std::ostream &operator<<(const std::ostream &flux, const AForm &ref);