#include "../includes/Span.hpp"
#include <iostream>

int main() {
	std::cout << MAGENT " ============ TEST 1: TEST OF SUBJECT ============ " RESET << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << MAGENT " ========== TEST 2: TEST WITH NO CONTENT ON SPAN ========== " RESET << std::endl;
	std::cout << std::endl;
	Span sp2 = Span(5);
	try {
		std::cout << CYAN << "Shortest span: " << RESET;
		std::cout << sp2.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << CYAN << "Longest span: " << RESET;
		std::cout << sp2.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << MAGENT " ========== TEST 3: TEST WITH 10.000 NUMBERS ON SPAN ========== " RESET << std::endl;
	std::cout << std::endl;
	try {
		Span sp3 = Span(10000);
		for (int i = 0; i < 10000; i++) {
			sp3.addNumber(i);
		}
		std::cout << CYAN << "Shortest Span: " RESET << sp3.shortestSpan() << std::endl;
		std::cout << CYAN << "Longest Span: " RESET << sp3.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << MAGENT " ========== TEST 4: TEST DUPLICATED NUMBERS ========== " RESET << std::endl;
	std::cout << std::endl;
	try {
        Span sp4(3);
        sp4.addNumber(5);
        sp4.addNumber(5);
        sp4.addNumber(5);

        std::cout << CYAN << "Shortest Span: " RESET << sp4.shortestSpan() << std::endl;
        std::cout << CYAN << "Longest Span: " RESET << sp4.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cout << e.what() << RESET << std::endl;
    }
	std::cout << std::endl;

	std::cout << MAGENT " ========== TEST 5: TEST ADD MORE THAN SPAN SIZE ========== " RESET << std::endl;
	std::cout << std::endl;
	try {
		Span sp5(1);
		sp5.addNumber(5);
		sp5.addNumber(3);
	} catch (const std::exception &e) {
		std::cout << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	return 0;
}