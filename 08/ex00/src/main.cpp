#include "../includes/easyfind.hpp"

int main() {
    try {
        // Testando com um std::vector
        std::vector<int> vec;
        for (int i = 1; i <= 5; ++i) vec.push_back(i); // Preenche o vetor: 1, 2, 3, 4, 5

        std::cout << "Vector test: ";
        for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Searching for 3 in vector... ";
        std::vector<int>::iterator found = easyfind(vec, 3);
        std::cout << "Found: " << *found << std::endl;

        std::cout << "Searching for 10 in vector... ";
        easyfind(vec, 10); // Vai lançar exceção
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        // Testando com um std::list
        std::list<int> lst;
        for (int i = 10; i <= 15; ++i) lst.push_back(i); // Preenche a lista: 10, 11, 12, 13, 14, 15

        std::cout << "\nList test: ";
        for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Searching for 12 in list... ";
        std::list<int>::iterator found = easyfind(lst, 12);
        std::cout << "Found: " << *found << std::endl;

        std::cout << "Searching for 20 in list... ";
        easyfind(lst, 20); // Vai lançar exceção
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        // Testando com um std::deque
        std::deque<int> deq;
        for (int i = -5; i <= -1; ++i) deq.push_back(i); // Preenche o deque: -5, -4, -3, -2, -1

        std::cout << "\nDeque test: ";
        for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Searching for -3 in deque... ";
        std::deque<int>::iterator found = easyfind(deq, -3);
        std::cout << "Found: " << *found << std::endl;

        std::cout << "Searching for 0 in deque... ";
        easyfind(deq, 0); // Vai lançar exceção
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}