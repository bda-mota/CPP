#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	std::string	str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (i = 1; argv[i] ; i++)
		{
			str = argv[i];
			for (std::string::iterator it = str.begin(); it != str.end(); ++it)
				*it = static_cast<char>(std::toupper(static_cast<unsigned char>(*it)));
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return (0);
}
