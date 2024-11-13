#include "../includes/Data.hpp"
#include "../includes/Serializer.hpp"

int main() {
	Data* data = new Data();
	uintptr_t raw = Serializer::serialize(data);
	Data* copy = Serializer::deserialize(raw);

	std::cout << "data->getData(): " << data->getData() << std::endl;
	std::cout << "copy->getData(): " << copy->getData() << std::endl;

	delete data;
	return (0);
}