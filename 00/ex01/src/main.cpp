#include <iostream>
#include <iomanip>
#include <limits>
#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include "../includes/Defines.hpp"

void printMenu() {
	std::cout << std::endl;
	std::cout << CYAN << " - - - - - - - - - - - - - - " << std::endl;
	std::cout << "|    ☎️ PhoneBook Menu ☎️     |" << std::endl;
	std::cout << CYAN << " - - - - - - - - - - - - - - " << std::endl;
	std::cout << "1. " << GREEN << "ADD " << CYAN << "- Add a new contact" << std::endl;
	std::cout << CYAN << "2. " << GREEN << "SEARCH " << CYAN << "- Display contacts" << std::endl;
	std::cout << CYAN << "3. " << GREEN << "EXIT " << CYAN << "- Display contacts" << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "Enter your choice: " << RESET;
}

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		printMenu();
		std::getline(std::cin, command);
		if (std::cin.eof()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "EOF detected and input stream cleared." << std::endl;
		}

		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
		{
			phoneBook.exit();
			break;
		}
		else
			std::cerr << YELLOW << "Invalid command. Please try again." << RESET << std::endl;
	}
	return 0;
}
