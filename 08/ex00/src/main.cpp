#include "../includes/easyfind.hpp"

template <typename T>
void printContainer(const T& container) {
	std::cout << CYAN << "Container values: " << RESET;
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    try {
		std::cout << MAGENT " =============== TEST 1: WITH VECTOR =============== " RESET << std::endl;
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
		printContainer(vec);
        std::cout << CYAN << "Searching for 3 in vector: " << RESET << *easyfind(vec, 3) << std::endl;

		std::cout << MAGENT " =============== TEST 2: WITH LIST =============== " RESET << std::endl;
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);
		printContainer(lst);
        std::cout << CYAN <<"Searching for 20 in list: " << RESET << *easyfind(lst, 20) << std::endl;

		std::cout << MAGENT " =============== TEST 3: WITH DEQUE =============== " RESET << std::endl;
        std::deque<int> deq;
        deq.push_back(100);
        deq.push_back(200);
        deq.push_back(300);
		printContainer(deq);
        std::cout << CYAN <<"Searching for 200 in deque: " << RESET  << *easyfind(deq, 200) << std::endl;

        std::cout << MAGENT " =============== TEST 4: EXAMPLE WITH EXCEPTION =============== " RESET << std::endl;
        std::cout << CYAN <<"Searching for 99 in vector: " << RESET  << *easyfind(vec, 99) << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}