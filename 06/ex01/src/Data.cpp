#include "../includes/Data.hpp"

Data::Data(void) : _data(42) {}

Data::Data(const Data& other) : _data(other._data) {}

Data&	Data::operator=(const Data& other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

Data::~Data(void) {}

uint32_t	Data::getData(void) { return _data; }