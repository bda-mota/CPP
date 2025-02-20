#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc >= 2) {
		try {
			PmergeMe sort;
			std::cout << "Vector list: " << std::endl;
			sort.runVector(argc, argv);
			std::cout << "Main list: " << std::endl;
			sort.printVector(sort.getVectorMainList());
			std::cout << "-----------------" << std::endl;
			std::cout << "Deque list: " << std::endl;
			sort.runDeque(argc, argv);
			std::cout << "Main list: " << std::endl;
			sort.printDeque(sort.getDequeMainList());
		} catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}