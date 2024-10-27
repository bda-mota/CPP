#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <iostream>
# include <cstdlib>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	RobotomyRequestForm : public AForm {

private:

	std::string	_target;

public:

	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target);
	RobotomyRequestForm( const RobotomyRequestForm &other );
	RobotomyRequestForm& operator=( const RobotomyRequestForm &other );
	~RobotomyRequestForm( void );

	void	execute(Bureaucrat const & executor) const;

};

#endif
