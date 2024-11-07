#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm {

private:

	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;

public:

	AForm( void );
	AForm( std::string const name, int signGrade, int executeGrade );
	AForm( const AForm &other );
	AForm& operator=( const AForm &other );
	virtual ~AForm( void );

	class GradeTooHighException : public std::exception {
		public: 
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public: 
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
		public: 
		virtual const char* what() const throw();
	};

	class FormAlreadySignedException : public std::exception {
		public: 
		virtual const char* what() const throw();
	};

	const std::string	getAFormName( void ) const;
	bool				getAFormStatus( void ) const;
	int					getAFormSignGrade( void ) const;
	int					getAFormExecuteGrade( void ) const;
	void				beSigned( const Bureaucrat& bureaucrat );
	virtual void		execute(Bureaucrat const & executor) const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
