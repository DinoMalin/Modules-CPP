#pragma once
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &ref);
		~RobotomyRequestForm();

		const RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);

		void execute(const Bureaucrat& executor) const;
};