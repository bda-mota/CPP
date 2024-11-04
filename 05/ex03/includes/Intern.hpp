#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	AForm;

class	Intern  {

public:

	Intern( void );
	Intern( const Intern &other );
	Intern& operator=( const Intern &other );
	~Intern( void );

	AForm	*makeForm( const std::string formName, const std::string target );

};

#endif
