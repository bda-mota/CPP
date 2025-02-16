#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// METHODS

void BitcoinExchange::fillReferenceContainer(std::string dataFile) {
	std::string line;
	std::ifstream file(dataFile.c_str());

	if (!file.is_open()) {
		throw std::invalid_argument("could not open file " + dataFile);		
	}

	std::getline(file, line);
	removeSpaces(line);
	if (line != "date,exchange_rate") {
		throw InvalidReferenceHeader();
	}

	while (std::getline(file, line)) {		
		size_t pos = line.find(',');
		if (pos == std::string::npos) {
			throw InvalidReferenceData();
		}
		std::string date = line.substr(0, pos);
		std::string rate = line.substr(pos + 1);

		removeSpaces(date);
		removeSpaces(rate);
		_data[date] = atof(rate.c_str());
	}

	file.close();
}

void BitcoinExchange::parsingInputFile(std::string filename) {
	std::string line;
	
	std::ifstream file(filename.c_str());

	if (!file.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
	}

	std::getline(file, line);
	removeSpaces(line);
	if (line != "date | value") {
		throw InvalidInputHeader();
	}

	while (std::getline(file, line)) {
		size_t pos = line.find('|');	
		if (pos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pos);
		std::string amount = line.substr(pos + 1);

		removeSpaces(date);
		removeSpaces(amount);
		try {
			checkValue(amount);
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
			continue;
		}
		try {
			checkDate(date);
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
			continue;
		}
		//procurar data no map, se n achar, buscar a anterior mais próxima
		//calcular valor
		//if (_data.find(date) == _data.end()) {
		//	throw InvalidInputData();
		//}
		//std::cout << date << " => " << amount << " = " << _data[date] << std::endl;
	}

	file.close();
}

// EXCEPTIONS

const char* BitcoinExchange::InvalidReferenceData::what() const throw() {
	return "Invalid reference data.";
}

const char* BitcoinExchange::InvalidReferenceHeader::what() const throw() {
	return "Invalid header, must be: date,exchange_rate";
}

const char* BitcoinExchange::InvalidInputData::what() const throw() {
	return "Invalid input data, must be: year-month-day | value";
}

const char* BitcoinExchange::InvalidInputHeader::what() const throw() {
	return "Invalid header, must be: date | value";
}

