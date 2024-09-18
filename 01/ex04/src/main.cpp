#include <iostream>
#include <fstream>
#include "../includes/Defines.hpp"

namespace utilsReplace {

	int	displayError(const std::string& messageError) {
		std::cerr <<  RED << messageError << RESET << std::endl;
		return (1);
	}

	void	justCopy(std::ifstream& inputFile, std::ofstream& outputFile) {
		std::string line;
		
		while (std::getline(inputFile, line))
		{
			outputFile << line << std::endl;
		}
		inputFile.close();
		outputFile.close();
	}

	void	replaceString(std::string& line, const std::string& s1, const std::string& s2) {
		
		std::size_t	pos = 0;
		std::size_t	found = 0;

		while (true)
		{
			found = line.find(s1, pos);
			if (found == std::string::npos)
				break ;
			line.erase(found, s1.size());
			line.insert(found, s2);
			pos += s2.length();
		}
	}

	int	readFile(const std::string& filename, const std::string& s1, const std::string& s2)
	{
		std::ifstream inputFile(filename.c_str());
	 	std::ofstream outputFile((filename + ".replace").c_str());

		if (!inputFile) {
			return (utilsReplace::displayError("Erro ao abrir o arquivo."));	
		}
		if (!outputFile) {
			return (utilsReplace::displayError("Erro ao abrir o arquivo para escrita."));
		}
		if (s1 == "") {
			return (utilsReplace::displayError("Search string not allowed."));
		}
		if (s1 == s2) {
			utilsReplace::justCopy(inputFile, outputFile);
			return (0);
		}

		std::string line;
		while (std::getline(inputFile, line))
		{
			utilsReplace::replaceString(line, s1, s2);
			outputFile << line << std::endl;
		}

		if (outputFile.fail()) {
			return (utilsReplace::displayError("Erro ao gravar no arquivo."));	
		}
		inputFile.close();
		outputFile.close();
		return 0;
	}
}

int	main(int argc, char **argv)
{

	switch (argc)
	{
		case 1:
			utilsReplace::displayError("The arguments must be: <filename> s1 s2.");
			break;
		case 2:
			utilsReplace::displayError("Missing strings to search and replace.");
			break;
		case 3:
			utilsReplace::displayError("Missing string to replace.");
			break;
		case 4:
			utilsReplace::readFile(argv[1], argv[2], argv[3]);
			break;
		default:
			utilsReplace::displayError("Too many arguments.");
			break;
	}
	return 0;
}
