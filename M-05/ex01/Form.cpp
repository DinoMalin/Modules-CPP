#include "Form.hpp"

Form::Form() : _name("unnamed"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}
Form::Form(const Form &ref) : _name(ref._name), _signed(ref._signed),_gradeToSign(ref._gradeToSign), _gradeToExecute(ref._gradeToExecute) {}
Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute) : _name(name), _signed(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (this->_gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToSign > 150)
		throw Form::GradeTooLowException();
	if (this->_gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToExecute > 150)
		throw Form::GradeTooLowException();
}
Form::~Form() {}

const Form& Form::operator=(const Form &ref) {
	this->_signed = ref._signed;
	return *this;
}

const std::string Form::getName() const {return this->_name;}
bool Form::getSigned() const {return this->_signed;}
int Form::getGradeToSign() const {return this->_gradeToSign;}
int Form::getGradeToExecute() const {return this->_gradeToExecute;}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& flux, const Form &ref) {
	flux << "form " << ref.getName() << std::endl
	<< "is signed : " << ref.getSigned() << std::endl
	<< "minimum grade to sign : " << ref.getGradeToSign() << std::endl
	<< "minimum grade to execute : " << ref.getGradeToExecute() << std::endl;
	return flux;
}