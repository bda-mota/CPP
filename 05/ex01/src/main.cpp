#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main() {
	try {
		std::cout << YELLOW << "Test - Create Form with valid values:" << RESET << std::endl;
		Form f1("Form A", 50, 20);
		std::cout << f1 << std::endl;

		std::cout << MAGENT << "Bureaucrat with grade to sign" << RESET << std::endl;
		Bureaucrat b1("Alice", 45);
		std::cout << b1 << std::endl;

		b1.signForm(f1);
		std::cout << f1 << std::endl;

		std::cout << MAGENT << "Bureaucrat without grade to sign" << RESET << std::endl;
		Bureaucrat b2("Bob", 60);
		std::cout << b2 << std::endl;

		b2.signForm(f1);

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << YELLOW << "Test - Exceptions(form):" << RESET << std::endl;
	try {
		std::cout << MAGENT << "Form with grade out of bounds(too high)" << RESET << std::endl;
		Form f2("Form B", 0, 50);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		std::cout << MAGENT << "Form with grade out of bounds(too low)" << RESET << std::endl;
		Form f3("Formulário C", 151, 50);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}