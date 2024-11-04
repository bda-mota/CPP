#include "../includes/Form.hpp"

Form::Form( void ) : _name("Untitle"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

Form::Form( std::string name, int signGrade, int executeGrade ) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1) {
		GradeTooHighException();
	} else if (signGrade > 150 || executeGrade > 150) {
		GradeTooLowException();
	}
}

Form::Form( const Form &other) : _name(other._name), _isSigned(other._isSigned) , _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

Form&	Form::operator=( const Form &other ) {
    if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form( void ) {}

const std::string	Form::getFormName( void ) const { return _name; }
bool				Form::getFormStatus( void ) const { return _isSigned; }
int					Form::getFormSignGrade( void ) const { return _signGrade; }
int					Form::getFormExecuteGrade( void ) const { return _executeGrade; }

std::ostream& operator<<( std::ostream& os, const Form& form ) {
	os << "AForm: " << form.getFormName()
	<< ", Sign Grade: " << form.getFormSignGrade()
	<< ", Execute Grade: " << form.getFormExecuteGrade()
	<< ", Signed: " << (form.getFormStatus() ? "Yes" : "No") ;
	return os;
}

const char* Form::GradeTooHighException::what( void ) const throw() {
	return "grade too high";
}

const char* Form::GradeTooLowException::what( void ) const throw() {
	return "grade too low";
}

const char* Form::FormAlreadySignedException::what( void ) const throw() {
	return "form already signed";
}

void	Form::beSigned( const Bureaucrat& bureaucrat ) {
	if (bureaucrat.getGrade() > getFormSignGrade()) {
		throw GradeTooLowException();
	} else if (getFormStatus()) {
		throw FormAlreadySignedException();
	}
	this->_isSigned = true;
}