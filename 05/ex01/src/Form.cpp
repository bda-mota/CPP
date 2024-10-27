#include "../includes/Form.hpp"

Form::Form( void ) : _name("Untitle"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

Form::Form( std::string name, int signGrade, int executeGrade ) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1) {
		GradeTooHighException();
	} else if (signGrade > 150 || executeGrade > 150) {
		GradeTooLowException();
	}
}

Form::Form( const Form &other) : _name("Untitle"), _isSigned(false) , _signGrade(150), _executeGrade(150) {
	*this = other;
}

Form&	Form::operator=( const Form &other ) {
	if (this != &other) {
		const_cast<std::string&>(_name) = other.getFormName();
		_isSigned = other.getFormStatus();
		const_cast<int&>(_signGrade) = other.getFormSignGrade();
		const_cast<int&>(_executeGrade) = other.getFormExecuteGrade();
	}
	return *this;
}

Form::~Form( void ) {}

//getters
const std::string	Form::getFormName( void ) const { return _name; }
bool		Form::getFormStatus( void ) const { return _isSigned; }
int			Form::getFormSignGrade( void ) const { return _signGrade; }
int			Form::getFormExecuteGrade( void ) const { return _executeGrade; }

//overload
std::ostream& operator<<(std::ostream& os, const Form& form) {
	std::string	status;

	if (form.getFormStatus() == true) {
		status = "yes";
	} else {
		status = "no";
	}
    os << "Form: " << form.getFormName() << ", Sign Grade: " << form.getFormSignGrade() << ", Execute Grade: " << form.getFormExecuteGrade() << ", Signed: " << status ;
    return os;
}

//exceptions
const char* Form::GradeTooHighException::what( void ) const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what( void ) const throw() {
	return "Grade too low";
}

//besigned
void	Form::beSigned( const Bureaucrat& bureaucrat ) {
	if (bureaucrat.getGrade() <= getFormSignGrade()) {
		this->_isSigned = true;
	} else {
		throw GradeTooLowException();
	}
}