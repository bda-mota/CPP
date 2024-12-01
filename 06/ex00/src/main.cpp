#include "../includes/ScalarConverter.hpp"

int main(void)
{   
    std::string input;

    std::cout << "Enter a literal to convert: ";
    std::getline(std::cin, input);

    ScalarConverter::convert(input);

    return (0);
}