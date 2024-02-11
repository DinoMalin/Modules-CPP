#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", false, 145, 137), _target("unknown") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", false, 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : AForm(ref), _target(ref._target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref) {
	this->_target = ref._target;
	this->_signed = ref._signed;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	if (!this->_signed)
		throw AForm::FormNotSignedException();

	std::srand(std::time(0));
	int tree(rand() % 3 + 1);

	std::ofstream file;
	file.open((this->_target + "_shrubbery").c_str());

	if (tree == 1) {
		file <<
			"                                                         ." << std::endl <<
			"                                              .         ;  " << std::endl <<
			"                 .              .              ;%     ;;   " << std::endl <<
			"                   ,           ,                :;%  %;   " << std::endl <<
			"                    :         ;                   :;%;'     .,   " << std::endl <<
			"           ,.        %;     %;            ;        %;'    ,;" << std::endl <<
			"             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl <<
			"              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl <<
			"               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl <<
			"                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl <<
			"                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl <<
			"                    `:%;.  :;bd%;          %;@%;'" << std::endl <<
			"                      `@%:.  :;%.         ;@@%;'   " << std::endl <<
			"                        `@%.  `;@%.      ;@@%;         " << std::endl <<
			"                          `@%%. `@%%    ;@@%;        " << std::endl <<
			"                            ;@%. :@%%  %@@%;       " << std::endl <<
			"                              %@bd%%%bd%%:;     " << std::endl <<
			"                                #@%%%%%:;;" << std::endl <<
			"                                %@@%%%::;" << std::endl <<
			"                                %@@@%(o);  . '         " << std::endl <<
			"                                %@@@o%;:(.,'         " << std::endl <<
			"                            `.. %@@@o%::;         " << std::endl <<
			"                               `)@@@o%::;         " << std::endl <<
			"                                %@@(o)::;        " << std::endl <<
			"                               .%@@@@%::;         " << std::endl <<
			"                               ;%@@@@%::;.          " << std::endl <<
			"                              ;%@@@@%%:;;;. " << std::endl <<
			"                          ...;%@@@@@%%:;;;;,..    "
			<< std::endl;
	} else if (tree == 2) {
		file <<
			"                        &&& &&  & &&" << std::endl <<
			"                    && &\\/&\\|& ()|/ @, &&" << std::endl <<
			"                    &\\/(/&/&||/& /_/)_&/_&" << std::endl <<
			"                 &() &\\/&|()|/&\\/ '%\\\" & ()" << std::endl <<
			"                &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl <<
			"              &&   && & &| &| /& & % ()& /&&" << std::endl <<
			"               ()&_---()&\\&\\|&&-&&--%---()~" << std::endl <<
			"                   &&     \\|||" << std::endl <<
			"                           |||" << std::endl <<
			"                           |||" << std::endl <<
			"                           |||" << std::endl <<
			"                     , -=-~  .-^- _" << std::endl <<
			"                            `"
			<< std::endl;
	} else {
		file <<
			"                      # #### ####" << std::endl <<
			"                    ### \\/#|### |/####" << std::endl <<
			"                   ##\\/#/ \\||/##/_/##/_#" << std::endl <<
			"                 ###  \\/###|/ \\/ # ###" << std::endl <<
			"               ##_\\_#\\_\\## | #/###_/_####" << std::endl <<
			"              ## #### # \\ #| /  #### ##/##" << std::endl <<
			"               __#_--###`  |{,###---###-~" << std::endl <<
			"                         \\ }{" << std::endl <<
			"                          }}{" << std::endl <<
			"                          }}{" << std::endl <<
			"                          {{}" << std::endl <<
			"                    , -=-~{ .-^- _" << std::endl <<
			"                          `}" << std::endl <<
			"                           {"
			<< std::endl;
	}
	file.close();
}
