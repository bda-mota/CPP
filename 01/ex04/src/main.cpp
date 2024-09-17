#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::ifstream inputFile("text.txt");
	if (!inputFile) {
		std::cerr << "Erro ao abrir o arquivo." << std::endl;
		return 1;
	}
	std::ofstream outputFile("out.txt");
    if (!outputFile) {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
        return 1;
    }

	std::string line;
	while (std::getline(inputFile, line)) {
		outputFile << line << std::endl;
	}

    if (outputFile.fail()) {
        std::cerr << "Erro ao gravar no arquivo." << std::endl;
        return 1;
    }

	inputFile.close();
	outputFile.close();
	return 0;
}

	// if (argc == 4)
	// {
	// 	std::cout << "the arguments are corrent." << std::endl;
	// }
	// else
	// 	std::cout << "The arguments must be: <filename> s1 s2." << std::endl;
	// return 0;
