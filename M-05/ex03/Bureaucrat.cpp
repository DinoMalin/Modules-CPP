#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unnamed"), _grade(75) {}
Bureaucrat::Bureaucrat(const Bureaucrat &ref) : _name(ref._name), _grade(ref._grade) {}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::~Bureaucrat() {}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref) {
	this->_grade = ref._grade;
	return *this;
}

const std::string Bureaucrat::getName() const {return this->_name;}
int Bureaucrat::getGrade() const {return this->_grade;}

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade - 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << "."
		<< std::endl;
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn't sign " << form.getName()
		<< " because his grade is too low." << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << "." << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& flux, const Bureaucrat &ref) {
	flux << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
	return flux;
}