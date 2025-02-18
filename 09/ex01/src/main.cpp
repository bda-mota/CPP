#include "../includes/RPN.hpp"

int main(int argc, char **argv) {
	if (argc == 2) {
		RPN rpn;
		try {
			rpn.run(argv[1]);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
			return 1;
		}
	} else {
		std::cerr << "Error: invalid input | Usage: ./rpn [expression]" << std::endl;
		return 1;
	}
	return 0;
}