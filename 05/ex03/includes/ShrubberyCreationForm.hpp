#ifndef SHRUBBERRY_CREATION_FORM_HPP
# define SHRUBBERRY_CREATION_FORM_HPP

# include <iostream>
# include <fstream> 
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	ShrubberyCreationForm : public AForm {

private:

	std::string	_target;

public:

	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm &other );
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm &other );
	~ShrubberyCreationForm( void );

	void	execute( Bureaucrat const & executor ) const;

};

#endif
