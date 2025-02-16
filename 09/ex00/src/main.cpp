#include "../includes/BitcoinExchange.hpp"

int	run(std::string filename)
{	
	std::ifstream file(filename.c_str());

	if (!file.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return 1;
	}

	BitcoinExchange exchange;

	try {
		exchange.fillReferenceContainer("data.csv");
		exchange.parsingInputFile(filename);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid input | Usage: ./btc [filename]" << std::endl;
		return 1;
	}
	run(argv[1]);
	return 0;
}