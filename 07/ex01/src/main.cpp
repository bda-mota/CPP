#include <iostream>
#include "../includes/iter.hpp"

# define CYAN	"\033[96m"
# define MAGENT	"\033[95m"
#define RESET   "\033[0m"

int main(int, char**) {
    std::cout << MAGENT " =============== TEST 1: WITH INT ARRAY =============== " RESET << std::endl;

    int intArray[5] = {1, 2, 3, 4, 5};
    int sizeInt = 5;

    std::cout << CYAN "original int array: " RESET;
    iter(intArray, sizeInt, print);
    std::cout << std::endl;

    iter(intArray, sizeInt, static_cast<void(*)(int&)>(increment));

    std::cout << CYAN "modified array: " RESET;
    iter(intArray, sizeInt, print);
    std::cout << std::endl;

    std::cout << MAGENT " =============== TEST 2: WITH CHAR ARRAY =============== " RESET << std::endl;

    char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
    int sizeChar = 5;

    std::cout << CYAN "original char array: " RESET;
    iter(charArray, sizeChar, print);
    std::cout << std::endl;

    iter(charArray, sizeChar, static_cast<void(*)(char&)>(increment));

    std::cout << CYAN "modified array: " RESET;
    iter(charArray, sizeChar, print);
    std::cout << std::endl;

    std::cout << MAGENT " =============== TEST 3: WITH CHAR FLOAT =============== " RESET << std::endl;

    float floatArray[5] = {1.1f, 1.2f, 1.3f, 1.4f, 1.5f};
    int sizeFloat = 5;

    std::cout << CYAN "original char array: " RESET;
    iter(floatArray, sizeFloat, print);
    std::cout << std::endl;

    iter(floatArray, sizeFloat, static_cast<void(*)(float&)>(increment));

    std::cout << CYAN "modified array: " RESET;
    iter(floatArray, sizeFloat, print);
    std::cout << std::endl;

    return (0);
}