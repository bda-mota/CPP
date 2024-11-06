#include "../includes/Intern.hpp"

Intern::Intern( void ){
	std::cout  << "Intern is available."  << std::endl;
}

Intern::Intern( const Intern &other ) { 
	*this = other;
}

Intern& Intern::operator=( const Intern &other ) { 
	(void)other;
	return *this;
}

Intern::~Intern( void ) {};

AForm	*Intern::makeForm( const std::string formName, const std::string target ) {
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for ( int i = 0; i < 3 ; i++ ) {
		if ( formName == forms[i] ) {
			std::cout << "Intern creates " << formName << std::endl;
			switch (i)
			{
				case 0:
					return new PresidentialPardonForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new ShrubberyCreationForm(target);
			}
		}
	}
	std::cout << formName << " is a invalid!" << std::endl;
	return NULL;
}