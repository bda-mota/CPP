#include <iostream>
#include <fstream>
#include "../includes/Replace.hpp"

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::cout << "the arguments are corrent." << std::endl;
		Replace	operation(argv[1], argv[2], argv[3]);
		std::cout << "filename: " << operation.getFilename() << std::endl;
		std::cout << "S1: " << operation.getS1() << std::endl;
		std::cout << "S2: " << operation.getS2() << std::endl;

	}
	else
		std::cout << "The arguments must be: <filename> s1 s2." << std::endl;
	return 0;
}


	// std::ifstream inputFile("text.txt");
	// if (!inputFile) {
	// 	std::cerr << "Erro ao abrir o arquivo." << std::endl;
	// 	return 1;
	// }
	// std::ofstream outputFile("out.txt");
    // if (!outputFile) {
    //     std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
    //     return 1;
    // }

	// std::string line;
	// while (std::getline(inputFile, line)) {
	// 	outputFile << line << std::endl;
	// }

    // if (outputFile.fail()) {
    //     std::cerr << "Erro ao gravar no arquivo." << std::endl;
    //     return 1;
    // }

	// inputFile.close();
	// outputFile.close();
