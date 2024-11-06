#include "../includes/Intern.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
	Intern intern;
	Bureaucrat bob("Bob", 1);
	std::string formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation", "invalid form"};
	
	for (int i = 0; i < 4; ++i) {
		const std::string &formName = formNames[i];
		AForm *form = intern.makeForm(formName, "Target");

		if (form) {
			try {
				bob.signForm(*form);
				bob.executeForm(*form);
			} catch (std::exception &e) {
				std::cerr << RED << "Erro: " << e.what() << RESET << std::endl;
			}
			delete form;
		} else {
			std::cout << RED << "Fail to create form: " << RESET << formName << std::endl;
		}
		std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	}

	return 0;
}