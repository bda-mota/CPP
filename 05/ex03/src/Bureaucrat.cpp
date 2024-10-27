#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Unidentified"), _grade(150) {}

Bureaucrat::Bureaucrat( std::string const name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat& other) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) { }

const char* Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return "Grade too low";
}

const std::string	Bureaucrat::getName( void ) const { return _name; }
int					Bureaucrat::getGrade( void ) const { return _grade; }

void	Bureaucrat::upGrade() {
	if (_grade == 1) {
		throw GradeTooHighException();
	}
	_grade--; 
}

void	Bureaucrat::downGrade() {
	if (_grade == 150) {
		throw GradeTooLowException();
	}
	_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade();
	return os;
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getAFormName() << std::endl;
	} catch (std::exception& e) {
		std::cout << getName() << " couldn't sign " << form.getAFormName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getAFormName() << std::endl;
	} catch(std::exception & e) {
		std::cout << getName() << " couldn't execute " << form.getAFormName() << " because " << e.what() << std::endl;
	}
}
