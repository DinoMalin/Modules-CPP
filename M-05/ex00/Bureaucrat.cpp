#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unnamed"), _grade(75) {}
Bureaucrat::Bureaucrat(const Bureaucrat &inst) : _name(inst._name), _grade(inst._grade) {}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::~Bureaucrat() {}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat &inst) {
	this->_grade = inst._grade;
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

std::ostream& operator<<(std::ostream& flux, const Bureaucrat &inst) {
	flux << inst.getName() << ", bureaucrat grade " << inst.getGrade() << std::endl;
	return flux;
}