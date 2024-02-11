#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", false, 25, 5), _target("unknown") {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", false, 25, 5), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm(ref), _target(ref._target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref) {
	this->_target = ref._target;
	this->_signed = ref._signed;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}