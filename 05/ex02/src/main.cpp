#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main() {
	try {
		std::cout << MAGENT << "Create a Bureaucrat " << RESET << std::endl;
		Bureaucrat roger("Roger", 50);
		std::cout << roger << std::endl;

		std::cout << MAGENT << "Create forms " << RESET << std::endl;
		ShrubberyCreationForm shrubForm("home");
		RobotomyRequestForm robotForm("target1");
		PresidentialPardonForm pardonForm("target2");

		std::cout << shrubForm << std::endl;
		std::cout << robotForm << std::endl;
		std::cout << pardonForm << std::endl;

		std::cout << MAGENT << "Signing forms..." << RESET << std::endl;
		roger.signForm(shrubForm);
		roger.signForm(robotForm);
		roger.signForm(pardonForm);

		std::cout << MAGENT << "Increment grade of Bureaucrat " << RESET << std::endl;
		roger.upGrade();
		roger.upGrade();
		roger.signForm(robotForm);
		roger.signForm(shrubForm);
		roger.signForm(pardonForm);

		std::cout << MAGENT << "Incrementing... " << RESET << std::endl;
		for (int i = 0; i < 10; ++i) {
			roger.upGrade();
		}
		std::cout << roger << std::endl;

		std::cout << MAGENT << "Trying sign again " << RESET << std::endl;
		roger.signForm(shrubForm); 
		roger.signForm(pardonForm); 

		std::cout << MAGENT << "Execute " << RESET << std::endl;
		roger.executeForm(shrubForm);
		roger.executeForm(robotForm);
		roger.executeForm(pardonForm);

	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "Test - Invalid Grade: " << RESET << std::endl;
	try {
		Bureaucrat lowBureaucrat("LowBob", 151);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "Test - Try execute a form not signed: " << RESET << std::endl;
	ShrubberyCreationForm shrubForm("home");
	try {
		Bureaucrat anotherBureaucrat("Alice", 30);
		anotherBureaucrat.executeForm(shrubForm);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}