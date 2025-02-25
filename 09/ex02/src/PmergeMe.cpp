#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(PmergeMe const & other) : _vectorList(other._vectorList), _dequeList(other._dequeList) {};

PmergeMe & PmergeMe::operator=(PmergeMe const & other) {
	if (this != &other) {
		this->_vectorList = other._vectorList;
		this->_dequeList = other._dequeList;
	}
	return *this;
}

PmergeMe::~PmergeMe() {};

std::vector<int> PmergeMe::getVectorMainList() const { return _vectorList; }
std::deque<int> PmergeMe::getDequeMainList() const { return _dequeList; }

void	PmergeMe::isValidInput(int argc ,char **argv) {
	std::string input;
	
	if (argc < 3) {
		std::cout << "It is not possible to order with just one number." << std::endl;
	} else {
		for (int i = 1; i < argc; i++) {
			input = argv[i];
			isValidNumber(input);
		}
	}
}

void	PmergeMe::isValidNumber(std::string slice) {
	std::istringstream iss(slice);
	int number;

	if (slice[0] == '-') {
		throw std::runtime_error("Negative numbers are not allowed.");
	}
	if (slice[0] == '+') {
		throw std::runtime_error("unexpected character.");
	}
	iss >> number;
		if (iss.fail() || !iss.eof()) {
			throw std::runtime_error("invalid input.");
	}
}

int	PmergeMe::jacobsthalSequency(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	int prev2 = 0;
	int prev1 = 1;
	int current = 0;

	for (int i = 2; i <= n; i++) {
		current = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = current;
	}
	return current;
}
