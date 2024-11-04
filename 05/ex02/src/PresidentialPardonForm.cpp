#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5), _target("undefined") {
	std::cout  << "PresidentialPardonForm is available. Main target: " << _target << "." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout  << "PresidentialPardonForm is available. Main target: " << _target << "." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other ) : AForm(other), _target(other._target) { }

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm &other ) { 
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {};

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	if (!getAFormStatus()) {
		throw FormNotSignedException();
	} else if (executor.getGrade() > getAFormExecuteGrade()) {
		throw GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}