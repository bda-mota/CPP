#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {

private:

	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;

public:

	Form( void );
	Form( std::string const name, int signGrade, int executeGrade );
	Form( const Form &other );
	Form& operator=( const Form &other );
	~Form( void );

	class GradeTooHighException : public std::exception {
		public: 	
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public: 
		virtual const char* what() const throw();
	};

	class FormAlreadySignedException : public std::exception {
		public: 
		virtual const char* what() const throw();
	};

	const std::string	getFormName( void ) const;
	bool				getFormStatus( void ) const;
	int					getFormSignGrade( void ) const;
	int					getFormExecuteGrade( void ) const;
	void				beSigned( const Bureaucrat& bureaucrat );

};

std::ostream& operator<<( std::ostream& os, const Form& form );

#endif
