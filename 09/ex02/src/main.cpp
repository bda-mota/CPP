#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc >= 2) {
		try {
			PmergeMe sort;
			sort.isValidInput(argc, argv);
			sort.runVector(argc, argv);
			sort.runDeque(argc, argv);
		} catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}