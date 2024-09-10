#include <iostream>
#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include "../includes/Defines.hpp"

void printMenu()
{
	std::cout << MAGENT "=== PhoneBook Menu ===" << std::endl;
	std::cout << "1. ADD - Add a new contact" << std::endl;
	std::cout << "2. SEARCH - Display contacts" << std::endl;
	std::cout << "3. EXIT - Quit the program" << std::endl;
	std::cout << "Enter your choice: " RESET;
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		printMenu();
		std::getline(std::cin, command);

		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << CYAN "Exiting PhoneBook. Goodbye!" RESET << std::endl;
			break;
		}
		else
			std::cerr << YELLOW "Invalid command. Please try again." RESET << std::endl;
	}
	return 0;
}
