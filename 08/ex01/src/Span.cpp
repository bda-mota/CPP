#include "../includes/Span.hpp"

Span::Span(unsigned int N): _size(N), _numbers(){}

Span::Span(const Span& other): _size(other._size), _numbers(other._numbers){} 

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_size = other._size;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span(void) {}

// Exceptions:

const char* Span::ContainerIsFullException::what( void ) const throw() {
	return "The container is full! You can't add more numbers.";
}

const char* Span::CantCalculateSpanException::what( void ) const throw() {
	return "Can't calculate the span with less than 2 numbers.";
}

// Methods:

void Span::addNumber(int n) {
	if (_numbers.size() == _size) {
		throw ContainerIsFullException();
	}
	_numbers.push_back(n);
}

int Span::shortestSpan(void) {
	if (_numbers.size() < 2) {
		throw CantCalculateSpanException();
	}
	std::sort(_numbers.begin(), _numbers.end());
	int min = std::numeric_limits<int>::max();
	int distance;

	for (size_t i = 1; i < _numbers.size(); i++) {
		distance = _numbers[i] - _numbers[i - 1];
		if (distance < min) {
			min = distance;
		}
	}

	return min;
}

int Span::longestSpan(void) {
	if (_numbers.size() < 2) {
		throw CantCalculateSpanException();
	}
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	
	return max - min;
}
