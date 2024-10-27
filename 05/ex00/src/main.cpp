#include "../includes/Bureaucrat.hpp"

int main() {
	try {
		std::cout << YELLOW << "Test - Create Bureaucrat with default constructor:" << RESET << std::endl;
		Bureaucrat b;
		std::cout << b << std::endl;

		std::cout << YELLOW << "Test - Create Bureaucrat with valid grade:" << RESET << std::endl;
		Bureaucrat alice("Alice", 42);
		std::cout << alice << std::endl;

		std::cout << YELLOW << "Test - Try create a Bureaucrat with grade too high:" << RESET << std::endl;
		Bureaucrat bob("Bob", 0);
		std::cout << bob << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		std::cout << YELLOW << "Test - Try create a Bureaucrat with grade too low:" << RESET << std::endl;
		Bureaucrat charlie("Charlie", 151);
		std::cout << charlie << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		std::cout << YELLOW << "Test - Change grade:" << RESET << std::endl;
		Bureaucrat daisy("Daisy", 10);
		std::cout << daisy << std::endl;

		std::cout << MAGENT << "Increment grade of Daisy..." << RESET << std::endl;
		daisy.upGrade();
		std::cout << daisy << std::endl;

		std::cout << MAGENT << "Decrement grade of Daisy..." << RESET << std::endl;
		daisy.downGrade();
		std::cout << daisy << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		std::cout << YELLOW << "Test - Decrement until throw an exception:" << RESET << std::endl;
		Bureaucrat roger("roger", 145);
		std::cout << roger << std::endl;
		while (roger.getGrade() < 151) {
			roger.downGrade();
			std::cout << roger << std::endl;
		}

	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}