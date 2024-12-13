#include "../includes/Data.hpp"

Data::Data(void) : _name("something"), _value(42) {}

Data::Data(std::string name, uint32_t value) : _name(name), _value(value) {}

Data::Data(const Data& other) : _name(other._name), _value(other._value) {}

Data&	Data::operator=(const Data& other) {
	if (this != &other) {
		_name = other._name;
		_value = other._value;
	}
	return *this;
}

Data::~Data(void) {}

uint32_t	Data::getValue(void) const { return _value; }
std::string	Data::getName(void) const { return _name; }

std::ostream& operator<<( std::ostream& os, const Data& data ) {
	os << "data name: " << data.getName() << ", data value: " << data.getValue() ;
	return os;
}