#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& other) {
	(void)other;
}

Serializer&	Serializer::operator=(const Serializer& other) {
	(void)other;
	return *this;
}

Serializer::~Serializer(void) {};


uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}