#include "../includes/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>  // para std::find
#include <exception>  // para std::out_of_range


int main() {
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        std::cout << "Searching for 3 in vector: " << *easyfind(vec, 3) << std::endl;

        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);
        std::cout << "Searching for 20 in list: " << *easyfind(lst, 20) << std::endl;

        std::deque<int> deq;
        deq.push_back(100);
        deq.push_back(200);
        deq.push_back(300);
        std::cout << "Searching for 200 in deque: " << *easyfind(deq, 200) << std::endl;

        // Exemplo que gera uma exceção
        std::cout << "Searching for 99 in vector: " << *easyfind(vec, 99) << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}