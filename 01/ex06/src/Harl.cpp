#include "../includes/Harl.hpp"

Harl::Harl() {};

Harl::~Harl() {};

void	Harl::complain(std::string level) {
	int	findLevel = -1;
	std::string	arrayLevel[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4 ; i++) {
		if (arrayLevel[i] == level) {
			findLevel = i;
			break;
		}
	}

	switch (findLevel)
	{
		case 0:
			this->debug();
			// fall through
		case 1:
			this->info();
			// fall through
		case 2:
			this->warning();
			// fall through
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

void	Harl::debug() {
	std::cout << "[DEBUG]" << std::endl; 
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;

	std::cout << std::endl;
}

void	Harl::info() {
	std::cout << "[INFO]" << std::endl; 
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning() {
	std::cout << "[WWARNING]" << std::endl; 
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error() {
	std::cout << "[ERROR]" << std::endl; 
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}
