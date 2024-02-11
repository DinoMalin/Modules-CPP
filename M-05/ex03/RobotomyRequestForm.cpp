#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", false, 72, 45), _target("unknown") {}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", false, 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : AForm(ref), _target(ref._target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref) {
	this->_target = ref._target;
	this->_signed = ref._signed;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	if (!this->_signed)
		throw AForm::FormNotSignedException();

	std::cout << "Drrr... Drrr... Drrr... ";

	std::srand(std::time(0));
	
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << "The robotomy has failed." << std::endl;
}