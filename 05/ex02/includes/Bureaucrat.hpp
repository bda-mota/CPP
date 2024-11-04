#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

# define GREEN	"\033[92m"
# define RED	"\033[91m"
# define CYAN	"\033[96m"
# define YELLOW	"\033[93m"
# define BLUE	"\033[94m"
# define MAGENT	"\033[95m"
# define RESET	"\033[0m"

class AForm;

class	Bureaucrat {

private:

	const std::string	_name;
	int					_grade;

public:

	Bureaucrat( void );
	Bureaucrat( std::string const name, int grade );
	Bureaucrat( const Bureaucrat& other );
	Bureaucrat& operator=( const Bureaucrat& other );
	~Bureaucrat( void );

	class GradeTooHighException : public std::exception {
		public: 
		
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public: 
		
		virtual const char* what() const throw();
	};

	const std::string	getName( void ) const;
	int					getGrade( void ) const;
	void				upGrade( void );
	void				downGrade( void );
	void				signForm( AForm& form );
	void				executeForm( AForm const & form );
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat );

#endif
