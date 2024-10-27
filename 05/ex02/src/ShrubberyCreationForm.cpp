#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137), _target("undefined") {
	std::cout  << "ShrubberyCreationForm is available. Main target: " << _target << "." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout  << "ShrubberyCreationForm is available. Main target: " << _target << "." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ) : AForm(other), _target(other._target) { }

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other ) { 
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {};

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getAFormStatus()) {
		throw FormNotSignedException();
	} else if (executor.getGrade() > getAFormExecuteGrade()) {
		throw GradeTooLowException();
	}

	std::ofstream outFile((_target + "_shrubbery").c_str());

	if (!outFile.is_open()) {
		throw std::runtime_error("Não foi possível abrir o arquivo!");
	}

	outFile << "              ,@@@@@@@,                   " << std::endl;
	outFile << "      ,,,.   ,@@@@@@/@@,  .oo8888o.       " << std::endl;
	outFile << "   ,&%%&%&&%,@@@@@/@@@@@@,8888888/8o      " << std::endl;
	outFile << " ,%&%%&&%&&%,@@@@@@@/@@@888888888/88'     " << std::endl;
	outFile << "  %&&%&%&/%&&%@@@@@/ /@@@88888888888'     " << std::endl;
	outFile << "  %&&%/ %&%%&&@@@ V /@@' `8888 `/88'      " << std::endl;
	outFile << "  `&%&|` /%&'    |.|         |'|8'        " << std::endl;
	outFile << "      |o|        | |         | |          " << std::endl;
	outFile << "      |.|        | |         | |          " << std::endl;
	outFile << "     /_._\\__//__/  \\,___//__/.  \\_//     " << std::endl;

	outFile.close();
}
