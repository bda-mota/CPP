#include "../includes/AForm.hpp"

AForm::AForm( void ) : _name("Untitle"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm( std::string name, int signGrade, int executeGrade ) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1) {
		GradeTooHighException();
	} else if (signGrade > 150 || executeGrade > 150) {
		GradeTooLowException();
	}
}

AForm::AForm( const AForm &other) : _name(other._name), _isSigned(other._isSigned) , _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

AForm&	AForm::operator=( const AForm &other ) {
    if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm( void ) {}

const std::string	AForm::getAFormName( void ) const { return _name; }
bool				AForm::getAFormStatus( void ) const { return _isSigned; }
int					AForm::getAFormSignGrade( void ) const { return _signGrade; }
int					AForm::getAFormExecuteGrade( void ) const { return _executeGrade; }

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "AForm: " << form.getAFormName()
	<< ", Sign Grade: " << form.getAFormSignGrade()
	<< ", Execute Grade: " << form.getAFormExecuteGrade()
	<< ", Signed: " << (form.getAFormStatus() ? "Yes" : "No") ;
	return os;
}

const char* AForm::GradeTooHighException::what( void ) const throw() {
	return "grade too high";
}

const char* AForm::GradeTooLowException::what( void ) const throw() {
	return "grade too low";
}

const char* AForm::FormNotSignedException::what( void ) const throw() {
	return "form not signed";
}

const char* AForm::FormAlreadySignedException::what( void ) const throw() {
	return "form already signed";
}

void	AForm::beSigned( const Bureaucrat& bureaucrat ) {
	if (bureaucrat.getGrade() > getAFormSignGrade()) {
		throw GradeTooLowException();
	} else if (getAFormStatus()) {
		throw FormAlreadySignedException();
	}
	this->_isSigned = true;
}