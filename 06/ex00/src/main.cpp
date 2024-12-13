#include "../includes/ScalarConverter.hpp"
#include "../includes/auxiliaries.hpp"

int main(int argc, char **argv) {
	if (argc == 2) {
    	ScalarConverter::convert(argv[1]);
	}
    return (0);
}