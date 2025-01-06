#include "../includes/Array.hpp"
#include "../includes/Array.tpp"
#include <iostream>

#define BRIGHT_CYAN   "\033[96m"
#define BRIGHT_YELLOW "\033[93m"
#define RESET   "\033[0m"

struct ComplexType
{
    std::string name;
    int         age;
};

std::ostream &operator<<(std::ostream &os, const ComplexType &obj)
{
   os << " " << obj.name << ", age: "  << obj.age;
   return (os);
}

int main(void) {
	{
		std::cout << BRIGHT_YELLOW "============= ROUND 01: SIMPLE TESTS WITH INT ============= " RESET << std::endl;
		try {
			std::cout << BRIGHT_CYAN "=== Test 1: Empty Array ===" RESET << std::endl;
		Array<int> emptyArray;
		std::cout << "size of the array: " << emptyArray.size() << std::endl;
		
		std::cout << BRIGHT_CYAN "=== Test 2: Array [5] elements ===" RESET << std::endl;
		Array<int> fiveElements(5);
		std::cout << "size of the array: " << fiveElements.size() << std::endl;
		for (unsigned int i = 0; i < fiveElements.size(); i++)
			std::cout << "Element " << i << ": " << fiveElements[i] << std::endl;

		std::cout << BRIGHT_CYAN "=== Test 3: Modifying the values of fiveArray ===" RESET << std::endl;

		fiveElements[0] = 1;
		fiveElements[1] = 2;
		fiveElements[2] = 3;
		fiveElements[3] = 4;
		fiveElements[4] = 5;

		for (unsigned int i = 0; i <fiveElements.size(); i++)
			std::cout << "Element " << i << ": " << fiveElements[i] << std::endl;

		std::cout << BRIGHT_CYAN "=== Test 4: Invalid acess in index ===" RESET << std::endl;
		std:: cout << fiveElements[10] << std::endl;

		} catch (const std::exception& e) {
			std::cerr << "Exceção: " << e.what() << std::endl;
		}
    }
    {
       std::cout << BRIGHT_YELLOW "============= ROUND 02: DEEP COPY ============= " RESET << std::endl;
       std::cout << BRIGHT_CYAN "=== Test 5: Deep Copy ===" RESET << std::endl;
        Array<int> original(3);
        original[0] = 10;
        original[1] = 20;
        original[2] = 30;

        Array<int> copy = original;

        std::cout << "Original array: ";
        for (unsigned int i = 0; i < original.size(); i++)
            std::cout << original[i] << " ";
        std::cout << std::endl;

        std::cout << "Copy array: ";
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << std::endl;

        copy[0] = 100;
        std::cout << "After modifying the copy:" << std::endl;
        std::cout << "Original: " << std::endl;
		for (unsigned int i = 0; i < original.size(); i++)
            std::cout << original[i] << " ";
		std::cout << std::endl;
        std::cout << "Copy: " << std::endl;
		for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
		std::cout << std::endl;
    }
    {
        std::cout << BRIGHT_YELLOW "============= ROUND 02: COMPLEX TYPES ============= " RESET << std::endl;
        
        std::cout << BRIGHT_CYAN "=== Test 6: TwoPeople test ===" RESET << std::endl;
        Array<ComplexType> twoPeople(2);
        twoPeople[0].name = "Maria Eduarda";
        twoPeople[0].age = 27;
        twoPeople[1].name = "Carlos Rodrigues";
        twoPeople[1].age = 28;

        for (unsigned int i = 0; i < twoPeople.size(); i++)
            std::cout << "People: " << i + 1 << twoPeople[i] << std::endl;
        
        std::cout << BRIGHT_CYAN "=== Test 7: Deep Copy TwoPeople ===" RESET << std::endl;
        
        Array<ComplexType> copyTwoPeople = twoPeople;
        for (unsigned int i = 0; i < copyTwoPeople.size(); i++)
            std::cout << "People: " << i + 1 << copyTwoPeople[i] << std::endl;

        std::cout << BRIGHT_CYAN "=== Test 8: modifying the copy ===" RESET << std::endl;
        copyTwoPeople[0].name = "Juliana Soares";
        
        std::cout << "Original: " << twoPeople[0] << std::endl;
        std::cout << "Copy: " << copyTwoPeople[0] << std::endl;
    }
    return (0);
}

//#include <iostream>
//#define MAX_VAL 750
//int main(int, char**)
//{
//    Array<int> numbers(MAX_VAL);
//    int* mirror = new int[MAX_VAL];
//    srand(time(NULL));
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        const int value = rand();
//        numbers[i] = value;
//        mirror[i] = value;
//    }
//    //SCOPE
//    {
//        Array<int> tmp = numbers;
//        Array<int> test(tmp);
//    }

//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        if (mirror[i] != numbers[i])
//        {
//            std::cerr << "didn't save the same value!!" << std::endl;
//            return 1;
//        }
//    }
//    try
//    {
//        numbers[-2] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//    try
//    {
//        numbers[MAX_VAL] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }

//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        numbers[i] = rand();
//    }
//    delete [] mirror;
//    return 0;
//}