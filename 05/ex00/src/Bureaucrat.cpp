#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Unidentified"), _grade(150) {}

Bureaucrat::Bureaucrat( std::string const name, int grade) : _name(name){
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other) {
	const_cast<std::string&>(_name) = other._name;
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() { }

//Exceptions 

const char* Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return "Grade too low";
}

//Getters
const std::string	Bureaucrat::getName( void ) const { return _name; }
int	Bureaucrat::getGrade( void ) const { return _grade; }

//Setters
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

//Overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade();
    return os;
}

