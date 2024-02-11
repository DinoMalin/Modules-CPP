#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &ref);
		~PresidentialPardonForm();

		const PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);

		void execute(const Bureaucrat& executor) const;
};