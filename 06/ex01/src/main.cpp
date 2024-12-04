#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int main(void)
{
	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << MAGENT;
	std::cout << "***************** REINTERPRET CAST TEST *****************\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Creating data instance..." << std::endl;
	std::cout << "Printing pointer address of data instance..." << std::endl;
	std::cout << "Printing data informations..." << std::endl;
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	Data before(42);
	std::cout << "Data is in pointer: \t\t" << PURPLE << before << "\n\n";
	std::cout << before;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Creating raw pointer using reinterpret_cast (serializing)\n";
	std::cout << "Printing raw pointer address..." << std::endl;
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	uintptr_t raw = Serializer::serialize(before);
	std::cout << "Raw pointer is: \t\t" << raw << std::endl;


	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Deserializing raw pointer using reinterpret_cast...\n";
	std::cout << "Confirming that data pointer is still pointing\n";
	std::cout << "at the same address..." << std::endl;
	std::cout << "Printing new data informartion..." << std::endl;
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	Data after = Serializer::deserialize(raw);
	std::cout << "Data is still pointing at: \t" << PURPLE << after << "\n\n";
	std::cout << after;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Deleting data instance..." << std::endl;
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << MAGENT;
	std::cout << "---------------------- END OF TEST ----------------------\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << RESET << std::endl;

	return 0;
}
