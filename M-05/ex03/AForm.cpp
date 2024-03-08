#include "AForm.hpp"

AForm::AForm() : _name("unnamed"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}
AForm::AForm(const AForm &ref) : _name(ref._name), _signed(ref._signed),_gradeToSign(ref._gradeToSign), _gradeToExecute(ref._gradeToExecute) {}
AForm::AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute) : _name(name), _signed(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (this->_gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeToSign > 150)
		throw AForm::GradeTooLowException();
	if (this->_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}
AForm::~AForm() {}

const AForm& AForm::operator=(const AForm &ref) {
	this->_signed = ref._signed;
	return *this;
}

const std::string AForm::getName() const {return this->_name;}
bool AForm::getSigned() const {return this->_signed;}
int AForm::getGradeToSign() const {return this->_gradeToSign;}
int AForm::getGradeToExecute() const {return this->_gradeToExecute;}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& flux, const AForm &ref) {
	flux << "form " << ref.getName() << std::endl
	<< "is signed : " << ref.getSigned() << std::endl
	<< "minimum grade to sign : " << ref.getGradeToSign() << std::endl
	<< "minimum grade to execute : " << ref.getGradeToExecute();
	return flux;
}