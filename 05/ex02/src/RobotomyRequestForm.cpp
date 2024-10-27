#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45), _target("undefined") {
	std::cout  << "RobotomyRequestForm is available. Main target: " << _target << "." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout  << "RobotomyRequestForm is available. Main target: " << _target << "." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other ) : AForm(other), _target(other._target) { }

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm &other ) { 
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {};

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getAFormStatus()) {
		throw FormNotSignedException();
	} else if (executor.getGrade() > getAFormExecuteGrade()) {
		throw GradeTooLowException();
	}

	std::cout << "grunf, grunf, grunf..." << std::endl;

	if (rand() % 2 == 0) {
		std::cout << _target << " has been robotomized." << std::endl;
	} else {
		std::cout << "Rotobomy has failed." << std::endl;
	}
}
